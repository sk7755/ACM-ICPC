#include <cstdio>

int main()
{
	int n, m, k;

	scanf("%d %d %d", &n, &m, &k);

	long long arr[1000001];
	int cmd[10000][2];
	int c_k = 0;

	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &arr[i]);
	}

	for (int i = 0; i < m + k; i++)
	{
		int op, a, b;
		scanf("%d %d %d", &op, &a, &b);

		if (op == 1)
		{
			arr[a] = b;
		}
		else
		{
			cmd[c_k][0] = a;
			cmd[c_k++][1] = b;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		arr[i] += arr[i - 1];
	}
	for (int i = 0; i < c_k; i++)
	{
		printf("%lld\n", arr[cmd[i][1]] - arr[cmd[i][0] - 1]);
	}

	return 0;

	return 0;
}
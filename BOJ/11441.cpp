#include <cstdio>

int main()
{
	int sum[100001] = { 0, };
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		sum[i] = sum[i - 1] + tmp;
	}

	int m;
	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		printf("%d\n", sum[b] - sum[a - 1]);
	}

	return 0;
}
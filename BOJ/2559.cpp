#include <cstdio>

int main()
{
	int sum[100001] = { 0, };

	int n, k;

	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++)
	{
		int tmp;
		scanf("%d", &tmp);

		sum[i] = sum[i - 1] + tmp;
	}

	int max = -1000000000;
	for (int i = k; i <= n; i++)
	{
		if (max < sum[i] - sum[i - k])
			max = sum[i] - sum[i - k];
	}

	printf("%d\n", max);

	return 0;
}
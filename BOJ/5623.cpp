#include <cstdio>

int main()
{
	int n;

	scanf("%d", &n);

	long long sum[1001][1001] = { 0, };
	long long s[1001] = { 0, };
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			long long key;
			scanf("%lld", &key);
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + key;
		}
	}
	if (n == 2)
	{
		printf("1 1");
		return 0;
	}

	for (int i = 3; i <= n; i++)
	{
		s[i] = sum[i][i] / (i - 1) / 2 - sum[i - 1][i - 1] / (i - 2) / 2;
	}
	s[1] = sum[3][1] - sum[2][1] - s[3];
	s[2] = sum[2][1] - sum[1][1] - s[1];

	for (int i = 1; i <= n; i++)
		printf("%lld ",s[i]);

	return 0;
}
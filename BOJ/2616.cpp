#include <cstdio>

inline int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int dp[4][50001] = { 0, };
	int a[50001] = { 0, };

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		a[i] = a[i - 1] + tmp;
	}

	int k;
	scanf("%d", &k);

	for (int i = 1; i <= 3; i++)
	{
		for (int j = k; j <= n; j++)
		{
			int tmp = a[j] - a[j - k] + dp[i - 1][j - k];
			dp[i][j] = max(tmp, dp[i][j - 1]);
		}
	}

	printf("%d\n", dp[3][n]);

	return 0;
}
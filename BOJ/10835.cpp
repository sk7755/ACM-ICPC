#include <cstdio>

inline int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int n;
	scanf("%d", &n);

	int a[2001];
	int b[2001];
	int dp[2001][2001] = { 0, };

	for (int i = n ; i > 0; i--)
		scanf("%d", &a[i]);

	for (int i = n ; i > 0; i--)
		scanf("%d", &b[i]);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]);

			if (a[i] > b[j])
				dp[i][j] = max(dp[i][j], dp[i][j - 1] + b[j]);
		}
	}

	printf("%d\n", dp[n][n]);
}
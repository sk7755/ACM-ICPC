#include <cstdio>

inline int max(int a, int b)
{
	return a > b?a : b;
}

int main()
{
	int t;
	scanf("%d", &t);

	int a[1001];
	int dp[1001][1001];
	int sum[1001] = { 0, };
	while (t--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]), dp[i][i] = a[i], sum[i] = sum[i-1]+a[i];

		for (int l = 1; l < n; l++)
		{
			for (int i = 1; i + l <= n; i++)
			{
				int j = i + l;

				dp[i][j] = max(a[i] + sum[j] - sum[i] - dp[i + 1][j], a[j] + sum[j-1] - sum[i-1] - dp[i][j-1]);
			}
		}

		printf("%d\n", dp[1][n]);


	}
}


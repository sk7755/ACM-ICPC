#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);

	int dp[1000001][20] = { 0, };
	int m = 1000000000;
	dp[0][0] = 1;
	dp[1][0] = 1;

	for (int i = 2; i <= n; i++)
	{
		int j = 1;
		int k = 0;
		while (i >= j)
		{
			for (int t = 0; t <= k; t++)
			{
				dp[i][k] = (dp[i][k] + dp[i - j][t]) % m;
			}
			j *= 2;
			k++;
		}
	}
	
	int ans = 0;

	for (int i = 0; i < 20; i++)
	{
		ans = (ans + dp[n][i]) % m;
	}

	printf("%d\n", ans);
	return 0;
}
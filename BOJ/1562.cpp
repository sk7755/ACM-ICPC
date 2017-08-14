#include <cstdio>

enum{m = 1000000000};

int main()
{
	int dp[401][10][10][10] = { 0, };

	for (int i = 1; i < 10; i++)
		dp[1][i][i][i] = 1;

	int n;
	scanf("%d", &n);

	for (int p = 2; p <= n; p++)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = i+1; j < 10; j++)
			{
				dp[p][i][j][i] = (dp[p-1][i + 1][j][i+1] + dp[p-1][i][j][i+1])%m;
				for (int k = i + 1; k < j; k++)
					dp[p][i][j][k] = (dp[p-1][i][j][k - 1] + dp[p-1][i][j][k + 1])%m;
				dp[p][i][j][j] = (dp[p-1][i][j - 1][j - 1] + dp[p-1][i][j][j-1])%m;
			}
		}
	}
	int ans = 0;

	for (int i = 0; i < 10; i++)
		ans = (ans + dp[n][0][9][i]) % m;

	printf("%d\n", ans);
}
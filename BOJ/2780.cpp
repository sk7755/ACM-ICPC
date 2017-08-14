#include <cstdio>

enum {m = 1234567};

int main()
{
	int dp[1001][10] = { 0, };
	
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= 1000; i++)
	{
		dp[i][0] = dp[i - 1][7];
		dp[i][1] = dp[i - 1][2] + dp[i - 1][4];
		dp[i][2] = dp[i - 1][1] + dp[i - 1][5] + dp[i - 1][3];
		dp[i][3] = dp[i - 1][2] + dp[i - 1][6];
		dp[i][4] = dp[i - 1][1] + dp[i - 1][5] + dp[i - 1][7];
		dp[i][5] = dp[i - 1][2] + dp[i - 1][4] + dp[i - 1][6] + dp[i - 1][8];
		dp[i][6] = dp[i - 1][3] + dp[i - 1][5] + dp[i - 1][9];
		dp[i][7] = dp[i - 1][4] + dp[i - 1][8] + dp[i - 1][0];
		dp[i][8] = dp[i - 1][5] + dp[i - 1][7] + dp[i - 1][9];
		dp[i][9] = dp[i - 1][6] + dp[i - 1][8];

		for (int j = 0; j < 10; j++)
			dp[i][j] %= m;
	}

	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n;
		scanf("%d", &n);

		int ans = 0;
		for (int i = 0; i < 10; i++)
			ans = (ans + dp[n][i]) % m;
		printf("%d\n", ans);
	}

	return 0;
}
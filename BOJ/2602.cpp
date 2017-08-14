#include <cstdio>
#include <cstring>

int main()
{
	int dp[21][2][101] = { 0, };

	char paper[21];
	char bridge[2][101];
	scanf("%s", paper);
	scanf("%s %s", bridge[0], bridge[1]);

	int n = strlen(paper);
	int m = strlen(bridge[0]);

	for (int i = 0; i < m; i++)
	{
		dp[1][0][i + 1] = dp[1][0][i];
		if (bridge[0][i] == paper[0])
			dp[1][0][i + 1]++;

		dp[1][1][i + 1] = dp[1][1][i];
		if (bridge[1][i] == paper[0])
			dp[1][1][i + 1]++;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dp[i + 1][0][j + 1] = dp[i + 1][0][j];
			if (bridge[0][j] == paper[i])
				dp[i + 1][0][j + 1] += dp[i][1][j];
			
			dp[i + 1][1][j + 1] = dp[i + 1][1][j];
			if (bridge[1][j] == paper[i])
				dp[i + 1][1][j + 1] += dp[i][0][j];
		}
	}
	printf("%d\n", dp[n][0][m] + dp[n][1][m]);

	return 0;
}
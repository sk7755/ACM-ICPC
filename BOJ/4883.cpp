#include <cstdio>

inline int min(int a, int b)
{
	return a > b ? b : a;
}

int main()
{
	int dp[2][5];

	dp[0][0] = dp[0][4] = dp[1][0] = dp[1][4] = 100000000;

	for (int i = 1;; i++)
	{
		int n;
		scanf("%d", &n);

		if (n == 0)
			return 0;

		int up = 0, down = 1;

		for (int j = 1; j <= 3; j++)
			scanf("%d", &dp[up][j]);
		dp[up][1] = 100000000;
		dp[up][3] += dp[up][2];

		for (int k = 1; k < n; k++)
		{
			for (int j = 1; j <= 3; j++)
			{
				int w;
				scanf("%d", &w);
				dp[down][j] = min(min(min(dp[down][j - 1], dp[up][j - 1]), dp[up][j]), dp[up][j + 1]) + w;
			}
			up ^= 1, down ^= 1;
		}

		printf("%d. %d\n", i, dp[up][2]);
	}
}
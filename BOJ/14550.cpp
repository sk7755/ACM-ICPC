#include <cstdio>

int main()
{

	while (1)
	{
		int n;
		scanf("%d", &n);
		if (n == 0)
			return 0;

		int s, t;
		scanf("%d %d", &s, &t);

		int table[300] = { 0, };
		int dp[2][300] = { 0, };

		for (int i = 1; i <= n + 1; i++)
			dp[0][i] = dp[1][i] = -1000000000;
		for (int i = 1; i <= n; i++)
			scanf("%d", &table[i]);

		int up = 0, down = 1;
		int ans = -1000000000;
		for (int i = 0; i < t; i++)
		{
			for (int j = 1; j <= n + 1 && j <= (i+1)*s; j++)
			{
				int max = -1000000000;
				for (int k = 1; j-k >= i && k <= s; k++)
				{
					if (dp[up][j - k] > max)
						max = dp[up][j - k];
				}
				dp[down][j] = max + table[j];
			}
			if (dp[down][n + 1] > ans)
				ans = dp[down][n + 1];
			up ^= 1, down ^= 1;
		}

		printf("%d\n", ans);
		
	}
}
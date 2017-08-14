#include <cstdio>

inline int min(int a, int b)
{
	return a > b ? b : a;
}

int main()
{
	int dp[501][501] = { 0, };
	int w[501] = { 0, };

	int t;
	scanf("%d", &t);

	while (t--)
	{
		int k;

		scanf("%d", &k);

		for (int i = 1; i <= k; i++)
			scanf("%d", &w[i]);

		for (int i = 1; i <= k; i++)
			w[i] += w[i - 1];

		for (int l = 1; l < k; l++)
		{
			for (int i = 1; i <= k - l; i++)
			{
				int j = i + l;
				dp[i][j] = 1000000000;
				for (int s = i; s < j; s++)
					dp[i][j] = min(dp[i][j], dp[i][s] + dp[s + 1][j]);

				dp[i][j] += w[j] - w[i - 1];
			}
		}

		printf("%d\n", dp[1][k]);
	}

	return 0;
}
#include <cstdio>

inline int MAX(int a, int b)
{
	if (a < b)
		return b;
	else
		return a;
}

int main()
{
	int t, w;
	int dp[3][31] = { 0, };

	scanf("%d %d", &t, &w);


	int ans = 0;
	for (int i = 0; i < t; i++)
	{
		int tree;
		scanf("%d", &tree);

		if (tree == 1)
		{
			dp[1][0]++;
			for (int i = 1; i <= w; i++)
				dp[1][i] = MAX(dp[2][i - 1], dp[1][i]) + 1;

			for (int i = 0; i <= w; i++)
			{
				if (ans < dp[1][i])
					ans = dp[1][i];
			}
		}
		else
		{
			dp[2][0]++;
			for (int i = 1; i <= w; i++)
				dp[2][i] = MAX(dp[1][i - 1], dp[2][i]) + 1;

			for (int i = 0; i <= w; i++)
			{
				if (ans < dp[2][i])
					ans = dp[2][i];
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}
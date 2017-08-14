#include <cstdio>

int main()
{
	int n;

	long long dp[100][100] = { 0, };
	dp[0][0] = 1;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int jump;
			scanf("%d", &jump);
			if (jump)
			{

				if (i + jump < n)
					dp[i + jump][j] += dp[i][j];
				if (j + jump < n)
					dp[i][j + jump] += dp[i][j];
			}
		}
	}

	printf("%lld\n", dp[n - 1][n - 1]);

	return 0;
}
#include <cstdio>

int main()
{
	int dp[46][2];

	int k;

	scanf("%d", &k);

	dp[0][0] = 1, dp[0][1] = 0;
	dp[1][0] = 0, dp[1][1] = 1;

	for (int i = 2; i <= k; i++)
	{
		dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
	}

	printf("%d %d\n", dp[k][0], dp[k][1]);

	return 0;
}
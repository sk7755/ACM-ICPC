#include <cstdio>

int main()
{
	int n, k;
	int dp[31][2] = { 0, };

	dp[1][0] = dp[2][1] = 1;

	scanf("%d %d", &n, &k);

	for (int i = 3; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
	}

	int i,j;
	for (i = 1; (k- dp[n][0] * i) % dp[n][1]; i++)
		;
	printf("%d\n%d\n", i, (k - dp[n][0] * i) / dp[n][1]);

	return 0;
}
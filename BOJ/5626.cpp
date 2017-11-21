#include <cstdio>

enum{m = 1000000007};

int main()
{
	int n;
	scanf("%d", &n);
	int h[10000] = { 0, };
	long long dp[2][5001] = { 0, };
	int up = 0, down = 1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &h[i]);
	}

	if (h[0] > 0 || h[n-1] > 0)
	{
		printf("0\n");
		return 0;
	}

	h[n - 1] = 0;
	dp[up][0] = 1;
	for (int i = 1; i < n; i++)
	{
		if (h[i] == -1)
		{
			dp[down][0] = dp[up][0] + dp[up][1];
			dp[down][5000] = dp[up][5000] + dp[up][4999];
			for (int j = 1; j < 5000; j++)
				dp[down][j] = (dp[up][j - 1] + dp[up][j] + dp[up][j + 1]) % m;
		}
		else
		{
			for (int j = 0; j <= 5000; j++)
				dp[down][j] = 0;
			dp[down][h[i]] = dp[up][h[i]];
			if (h[i] > 0)
				dp[down][h[i]] += dp[up][h[i] - 1];
			if (h[i] < 5000)
				dp[down][h[i]] += dp[up][h[i] + 1];
			dp[down][h[i]] %= m;
		}
		up ^= 1, down ^= 1;
	}

	printf("%lld\n", dp[up][0]);
}
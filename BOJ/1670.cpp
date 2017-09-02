#include <cstdio>

enum{m = 987654321};

int main()
{
	int n;
	scanf("%d", &n);

	long long dp[10001] = { 0, };

	dp[0] = 1;
	dp[2] = 1;
	for (int i = 4; i <= n; i+=2)
	{
		for (int j = 0; j <= i - 2; j++)
		{
			dp[i] = (dp[i] + (dp[j] * dp[i - 2 - j]) % m)%m;
		}
	}

	printf("%lld\n", dp[n]);
}
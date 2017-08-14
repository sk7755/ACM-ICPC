#include <cstdio>

int main()
{
	int n;
	int m = 1000000000;

	scanf("%d", &n);

	int dp[1000001] = { 1,0, };

	for (int i = 1; i <= n; i *= 2)
	{
		for (int j = i; j <=n; j++)
		{
			dp[j] = (dp[j] + dp[j - i])%m;
		}
	}

	printf("%d\n", dp[n]);
}
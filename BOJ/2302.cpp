#include <cstdio>

int main()
{
	int dp[41] = { 1,1,2,0,};
	int n;
	scanf("%d", &n);

	for (int i = 3; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	int m;
	scanf("%d", &m);

	int pre = 0;
	int ans = 1;
	for (int i = 0; i < m; i++)
	{
		int vip;

		scanf("%d", &vip);
		ans *= dp[vip - pre - 1];
		pre = vip;
	}
	ans *= dp[n - pre];
	printf("%d\n", ans);
}
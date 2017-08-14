#include <cstdio>

int main()
{
	int a[201];
	int dp[201] = { 0, };
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int max = 0;
		for (int j = 1; j < i; j++)
		{
			if (a[i] > a[j] && dp[j] > max)
			{
				max = dp[j];
			}
		}
		dp[i] = max + 1;
		if (ans < dp[i])
			ans = dp[i];
	}
	printf("%d\n", n - ans);

	return 0;
}
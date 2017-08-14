#include <cstdio>

int main()
{
	int t, k;
	int dp[10001] = { 1, 0, };

	scanf("%d %d", &t, &k);

	for (int i = 0; i < k; i++)
	{
		int p, n;
		scanf("%d %d", &p, &n);

		for (int j = t;j>0;j--)
		{
			for (int l = 1; l <= n && j - l*p >= 0; l++)
			{
				dp[j] += dp[j - l*p];
			}
		}
	}
	printf("%d\n", dp[t]);

	return 0;
}
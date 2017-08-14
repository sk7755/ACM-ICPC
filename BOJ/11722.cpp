#include <cstdio>

int main()
{
	int n;
	int a[1000];
	int dp[1000] = { 0, };

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		int max = 0;
		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[i])
			{
				if (dp[j] > max)
					max = dp[j];
			}
		}
		dp[i] += max;
		if (ans < dp[i])
			ans = dp[i];
	}

	printf("%d\n", ans);

	return 0;

}
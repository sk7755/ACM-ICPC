#include <cstdio>

int main()
{
	int dp[40000] = { 0, };
	int a[40000];
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int max = 0;
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j] && max < dp[j])
				max = dp[j];
		}
		dp[i] = max + 1;

		if (ans < dp[i])
			ans = dp[i];
	}
	printf("%d\n", ans);

	return 0;
}
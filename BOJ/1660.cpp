#include <cstdio>

inline int min(int a, int b)
{
	return a > b ? b : a;
}

int main()
{
	int a[122];
	int dp[300001] = { 0, };
	for (int i = 1; i <= 121; i++)
		a[i] = i*(i + 1)*(i + 2) / 6;

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		dp[i] = 300000;
		for (int j = 1;i-a[j]>=0; j++)
			dp[i] = min(dp[i], dp[i - a[j]]);
		dp[i]++;
	}
	printf("%d\n", dp[n]);
	return 0;
}
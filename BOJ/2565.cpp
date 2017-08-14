#include <cstdio>

int main()
{
	int n;
	int a[501] = { 0, };
	int b[101] = { 0, };
	int dp[101] = { 0, };
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		a[u] = v;
	}

	for (int i = 1, k = 1; i <= 500; i++)
	{
		if (a[i])
			b[k++] = a[i];
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int max = 0;
		for (int j = 1; j < i; j++)
		{
			if (b[j] < b[i] && max < dp[j])
			{
				max = dp[j];
			}
		}
		dp[i] = max + 1;
		if (ans < dp[i])
			ans = dp[i];
	}

	printf("%d\n", n - ans);
}
#include <cstdio>

inline int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int n, m;
	int dp[2][1001] = { 0, };
	int left[1001] = { 0, }, right[1001] = { 0, };
	int a[1001];
	scanf("%d %d", &n,&m);

	int up = 0, down = 1;

	for (int i = 1; i <= m; i++)
		scanf("%d", &dp[up][i]), dp[up][i] += dp[up][i-1];

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[j]);

		left[1] = dp[up][1] + a[1];
		for (int j = 2; j <= m; j++)
		{
			if (left[j-1] > dp[up][j])
				left[j] = left[j-1] + a[j];
			else
				left[j] = dp[up][j] + a[j];
		}
		right[m] = dp[up][m] + a[m];
		for (int j = m-1; j >= 1; j--)
		{
			if (right[j + 1] > dp[up][j])
				right[j] = right[j + 1] + a[j];
			else
				right[j] = dp[up][j] + a[j];
		}

		for (int j = 1; j <= m; j++)
			dp[down][j] = max(left[j], right[j]);

		up ^= 1;
		down ^= 1;
	}

	printf("%d\n", dp[up][m]);

	return 0;
}
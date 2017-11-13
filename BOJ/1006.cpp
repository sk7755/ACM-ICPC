#include <cstdio>

inline int min(int a, int b)
{
	return a > b ? b : a;
}

void init_base(int dp[][4][3], int a[][10000], int n, int w);

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n, w;
		scanf("%d %d", &n, &w);

		int a[2][10000];
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &a[i][j]);
			}
		}

		if (n == 1)
		{
			if (a[0][0] + a[1][0] <= w)
				printf("1\n");
			else
				printf("2\n");
			continue;
		}

		int dp[10000][4][3] = { 0, };

		init_base(dp, a, n, w);

		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = 2 * n;
				if (a[0][i - 1] + a[0][i] <= w)
					dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][1] + 1);
				dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][2] + 1);
				
				if (a[1][i - 1] + a[1][i] <= w)
					dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][0] + 1);
				dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][2] + 1);

				if (a[0][i] + a[1][i] <= w)
					dp[i][j][2] = min(dp[i][j][2], dp[i - 1][j][2] + 1);
				if (a[0][i] + a[0][i - 1] <= w && a[1][i] + a[1][i - 1] <= w)
				{
					if (i > 1)
						dp[i][j][2] = min(dp[i][j][2], dp[i - 2][j][2] + 2);
					if (i == 1 && j == 3)
						dp[i][j][2] = min(dp[i][j][2], 2);
				}

				dp[i][j][2] = min(dp[i][j][2], dp[i][j][0] + 1);
				dp[i][j][2] = min(dp[i][j][2], dp[i][j][1] + 1);
			}
		}

		int ans = 2 * n;
		ans = min(ans, dp[n - 1][0][1]);
		ans = min(ans, dp[n - 1][1][0]);
		ans = min(ans, dp[n - 2][2][2]);
		ans = min(ans, dp[n - 1][3][2]);

		printf("%d\n", ans);
	}

	
}

void init_base(int dp[][4][3], int a[][10000], int n, int w)
{
	if (a[0][0] + a[0][n - 1] <= w)
	{
		dp[0][0][0] = 1;
		dp[0][0][1] = 2 * n;
		dp[0][0][2] = 2;
	}
	else
		dp[0][0][0] = dp[0][0][1] = dp[0][0][2] =  2 * n;

	if (a[1][0] + a[1][n - 1] <= w)
	{
		dp[0][1][0] = 2 * n;
		dp[0][1][1] = 1;
		dp[0][1][2] = 2;
	}
	else
		dp[0][1][0] = dp[0][1][1] = dp[0][1][2] = 2 * n;

	if (a[0][0] + a[0][n - 1] <= w && a[1][0] + a[1][n - 1] <= w)
	{
		dp[0][2][0] = 2 * n;
		dp[0][2][1] = 2 * n;
		dp[0][2][2] = 2;
	}
	else
		dp[0][2][0] = dp[0][2][1] = dp[0][2][2] = 2 * n;

	if (a[0][0] + a[1][0] <= w)
		dp[0][3][2] = 1;
	else
		dp[0][3][2] = 2;
	dp[0][3][0] = dp[0][3][1] = 1;
}
#include <cstdio>

struct rec
{
	int w, h;
};

inline int min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

inline int max(int a, int b)
{
	if (a < b)
		return b;
	else
		return a;
}
inline void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	while (true)
	{
		int n, m;
		rec dp[2][1001] = { 0, };
		scanf("%d %d", &n, &m);

		if (n == 0 && m == 0)
			return 0;
		int up = 0, down = 1;

		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int tmp;
				scanf("%d", &tmp);
				if (tmp == 0)
				{
					dp[down][j + 1].h = dp[down][j + 1].w = 0;
				}
				else
				{
					int h, w;

					dp[down][j + 1].h = min(dp[up][j + 1].h + 1, dp[down][j].h);
					dp[down][j + 1].w = dp[down][j].w + 1;

					w = min(dp[down][j].w, dp[up][j].w) + 1;
					h = min(dp[up][j].h, dp[up][j + 1].h) + 1;

					if (dp[down][j + 1].h * dp[down][j + 1].w < h*w)
					{
						dp[down][j + 1].h = h;
						dp[down][j + 1].w = w;
					}

					h = dp[up][j + 1].h + 1;
					w = min(dp[down][j].w + 1, dp[up][j + 1].w);

					if (dp[down][j + 1].h * dp[down][j + 1].w < h*w)
					{
						dp[down][j + 1].h = h;
						dp[down][j + 1].w = w;
					}

					if (ans < dp[down][j + 1].h * dp[down][j + 1].w)
						ans = dp[down][j + 1].h * dp[down][j + 1].w;
				}
			}

			swap(up, down);
		}

		printf("%d\n", ans);
	}

	return 0;
}
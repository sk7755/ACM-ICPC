#include <cstdio>

int map[102][102] = { 0, };
int visit[102][102] = { 0, };
int stack[10000][2];
int top;

void dfs(int x, int y);

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);
	for (int i = 0; i <= m + 1; i++)
		visit[0][i] = visit[n + 1][i] = 1;
	for (int i = 0; i <= n + 1; i++)
		visit[i][0] = visit[i][m + 1] = 1;

	int remain = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &map[i][j]);
			remain += map[i][j];
		}
	}

	int hour = 0;
	while (remain)
	{
		hour++;
		top = -1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				visit[i][j] = 0;
		}
		dfs(1, 1);

		remain -= top + 1;

		while (top >= 0)
		{
			int x = stack[top][0];
			int y = stack[top--][1];
			map[x][y] = 0;
		}
	}
	printf("%d\n", hour);

	return 0;
}

int dir[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, {0,-1} };

void dfs(int x, int y)
{
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int n_x = x + dir[i][0];
		int n_y = y + dir[i][1];

		if (!visit[n_x][n_y] && !map[n_x][n_y])
			dfs(n_x, n_y);
		if (map[n_x][n_y])
		{
			visit[n_x][n_y]++;
			if (visit[n_x][n_y] == 2)
				stack[++top][0] = n_x, stack[top][1] = n_y;
		}
	}
}
#include <cstdio>

char map[102][102] = { 0, };
int visit[102][102] = { 0, };

void dfs(int x, int y);

int main()
{
	int n;
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++)
		scanf("%s", map[i] + 1);

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (!visit[i][j])
				dfs(i, j), ans++;
		}
	}
	printf("%d ", ans);
	ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			visit[i][j] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (!visit[i][j])
				dfs(i, j),ans++;
		}
	}
	printf("%d\n", ans);

	return 0;
}

int dir[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

void dfs(int x, int y)
{
	visit[x][y] = 1;

	for (int i = 0; i < 4; i++)
	{
		int n_x = x + dir[i][0];
		int n_y = y + dir[i][1];

		if (!visit[n_x][n_y] && map[x][y] == map[n_x][n_y])
			dfs(n_x, n_y);
	}

	if (map[x][y] == 'G')
		map[x][y] = 'R';
}
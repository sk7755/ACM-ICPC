#include <cstdio>


int n, m;
int map[100][100] = { 0, };
int visit[100][100] = { 0, };
int dir[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
int dfs(int x, int y);

int main()
{

	scanf("%d %d", &n, &m);

	int cheese = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j])
				cheese++;
		}
	}
	int day = 0;
	int del = 0;
	int temp;

	while (del != cheese)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				visit[i][j] = 0;
		}

		temp = dfs(0, 0), day++;
		del += temp;
	}

	printf("%d\n%d\n", day, temp);

	return 0;
}

int dfs(int x, int y)
{
	int ret = 0;
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int r = x + dir[i][0];
		int c = y + dir[i][1];

		if (0 <= r && r < n && 0 <= c && c < m)
		{
			if (!visit[r][c])
			{
				if (map[r][c])
				{
					ret++;
					visit[r][c] = 1;
					map[r][c] = 0;
				}
				else
					ret +=dfs(r, c);
			}
		}
	}

	return ret;
}
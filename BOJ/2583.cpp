#include <cstdio>
#include <algorithm>

using namespace std;

int paper[100][100] = { 0, };
int m, n;

int dfs(int x, int y);

int main()
{
	int  k;

	scanf("%d %d %d", &m, &n, &k);

	for (int i = 0; i < k; i++)
	{
		int x1, y1, x2, y2;

		scanf("%d %d %d %d", &y1, &x1, &y2, &x2);

		for (int i = x1; i < x2; i++)
		{
			for (int j = y1; j < y2; j++)
				paper[i][j] = 1;
		}
	}

	int num = 0;
	int ans[10000];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!paper[i][j])
			{
				ans[num++] = dfs(i, j);
			}
		}
	}

	sort(ans, ans + num);

	printf("%d\n", num);

	for (int i = 0; i < num; i++)
		printf("%d ", ans[i]);
	printf("\n");

	return 0;
}

int dir[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

int dfs(int x, int y)
{
	paper[x][y] = 1;

	int s = 1;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];

		if (0 <= nx && nx < m && 0 <= ny && ny < n)
		{
			if (!paper[nx][ny])
				s += dfs(nx, ny);
		}
	}

	return s;
}
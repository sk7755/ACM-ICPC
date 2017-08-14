//분리집합을 이용하면 더 빠르게 구현 가능할거 같다.
#include <cstdio>

int map[102][102] = { 0, };

void dfs(int r, int c);

int main()
{
	int n;
	int h[102][102] = { 0, };
	scanf("%d", &n);

	int max = 0;
	int min = 101;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &h[i][j]);
			if (max < h[i][j])
				max = h[i][j];
			if (min > h[i][j])
				min = h[i][j];
		}
	}

	int max_p = 0;
	for (int k = max; k >= min-1; k--)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (h[i][j] <= k)
				{
					map[i][j] = 0;
				}
				else
				{
					map[i][j] = 1;
				}
			}
		}
		int p = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (map[i][j])
					dfs(i,j), p++;
			}
		}

		if (max_p < p)
			max_p = p;
	}

	printf("%d\n", max_p);

	return 0;

}

int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
void dfs(int r, int c)
{
	map[r][c] = 0;

	for (int i = 0; i < 4; i++)
	{
		int x = r + dir[i][0];
		int y = c + dir[i][1];

		if (map[x][y])
		{
			dfs(x, y);
		}
	}

	return;
}
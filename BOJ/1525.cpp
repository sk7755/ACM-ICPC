#include <cstdio>

struct point
{
	int r, c;
};

inline void swap(int& a, int& b);
int check();

int puz[5][5];

int main()
{
	int start_r, start_c;

	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			scanf("%d", &puz[i][j]);
		}
	}

	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			if (puz[i][j] == 0)
			{
				start_r = i, start_c = j;
				break;
			}
		}
	}
}

inline void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

/*
int dfs(point start, int puz[][5])
{
	point stack[10];
	int top = -1;
	point dir[4] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
	int visit[5][5] = { 0, };

	stack[++top].r = start.r;
	stack[top].c = start.c;
	visit[start.r][start.c] = 1;

	int min = 10;

	while (top >= 0)
	{
		point cur = stack[top];

		if (cur.r == 3 && cur.c == 3)
		{
			if (check(puz))
			{
				if (min > top)
					min = top;
			}
		}

		int i;
		for (i = 0; i < 4; i++)
		{
			int x = cur.r + dir[i].r;
			int y = cur.c + dir[i].c;

			if (1 <= x && x <= 3 && 1 <= y && y <= 3)
			{
				if (!visit[x][y])
				{
					stack[++top].r = x;
					stack[top].c = y;
					visit[x][y] = 1;
					swap(puz[cur.r][cur.c], puz[x][y]);
					break;
				}
			}
		}

		if (i == 4)
		{
			top--;
			if (top >= 0)
			{
				point pre = stack[top];
				swap(puz[cur.r][cur.c], puz[pre.r][pre.c]);
			}
		}
	}

	if (min == 10)
		return -1;
	else
		return min;
}
*/
int check()
{
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			if (i != 3 || j != 3)
			{
				if (puz[i][j] != (i-1) * 3 + j)
					return 0;
			}
		}
	}

	return 1;
}
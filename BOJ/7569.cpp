#include <cstdio>

struct point
{
	int x, y, h;
};

int main()
{
	int map[102][102][102] = { 0, };
	point queue[1000000];
	int front = 0, rear = -1;

	int n, m, h;

	scanf("%d %d %d", &m, &n, &h);

	int tomato = 0;

	for (int k = 1; k <= h; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				int temp;
				scanf("%d", &temp);
				map[k][i][j] = temp + 1;
				if (map[k][i][j] == 2)
				{
					queue[++rear].x = i;
					queue[rear].y = j;
					queue[rear].h = k;
				}
				else if (map[k][i][j] == 0)
					tomato++;
			}
		}
	}


	tomato = n*m*h - tomato;

	int dir[6][3] = { { 0, 1, 0 }, { 0, 0, 1 }, { 0, -1, 0 }, { 0, 0, -1 }, { 1, 0, 0 }, { -1, 0, 0 } };
	int reap = 0;
	int day = -1;
	while (front <= rear)
	{
		int size = rear - front + 1;
		reap += size;
		day++;
		while (size--)
		{
			point cur = queue[front++];

			for (int i = 0; i < 6; i++)
			{
				int h = cur.h + dir[i][0];
				int x = cur.x + dir[i][1];
				int y = cur.y + dir[i][2];

				if (map[h][x][y] == 1)
				{
					queue[++rear].h = h;
					queue[rear].x = x;
					queue[rear].y = y;
					map[h][x][y] = 2;
				}
			}
		}
	}

	if (reap == tomato)
		printf("%d\n", day);
	else
		printf("-1\n");
}
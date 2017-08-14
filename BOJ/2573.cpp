#include <cstdio>

struct point
{
	int x, y;
};

int start_i = 1, start_j = 1;

inline void find_start(int map[][302], int n, int m)
{
	for (int i = start_i; i <= n; i++)
	{
		for (int j = start_j; j <= m; j++)
		{
			if (map[i][j])
			{
				start_i = i, start_j = j;
				return;
			}
		}
	}
}

int main()
{
	int map[2][302][302] = { 0, };
	int visit[302][302] = { 0, };
	int n, m;
	scanf("%d %d", &n, &m);

	int ice = 0;
	point queue[10000];
	int front = 0, rear = -1;
	int up = 0, down = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &map[up][i][j]);
			if (map[up][i][j])
				ice++;
		}
	}
	
	int day = 0;
	int melt = 0;
	point dir[4] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

	while (true)
	{
		day++;
		front = 0, rear = -1;

		find_start(map[up], n, m);
		queue[++rear] = { start_i, start_j };
		visit[start_i][start_j] = day;

		ice -= melt;
		melt = 0;

		while (front <= rear)
		{
			point cur = queue[front++];

			int speed = 0;
			for (int i = 0; i < 4; i++)
			{
				int x = cur.x + dir[i].x;
				int y = cur.y + dir[i].y;

				if (visit[x][y] != day && map[up][x][y])
				{
					queue[++rear] = { x, y };
					visit[x][y] = day;
				}
				if (!map[up][x][y])
					speed++;
			}

			map[down][cur.x][cur.y] = map[up][cur.x][cur.y] - speed;
			if (map[down][cur.x][cur.y] <= 0)
			{
				map[down][cur.x][cur.y] = 0;
				melt++;
			}
		}

		front = 0;
		while (front <= rear)
		{
			point cur = queue[front++];
			map[up][cur.x][cur.y] = 0;
		}
		up ^= 1, down ^= 1;

		if (ice != rear + 1 || ice == melt)
			break;
	} 

	if (ice != melt)
		printf("%d\n", day-1);
	else
		printf("0\n");

	return 0;
}
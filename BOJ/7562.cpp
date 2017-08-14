#include <cstdio>

struct point
{
	int x, y;
};

int bfs(point& start, point& end, int n);

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n;

		scanf("%d", &n);

		point start, end;

		scanf("%d %d %d %d", &start.x, &start.y, &end.x, &end.y);

		printf("%d\n", bfs(start, end, n));
	}
}

point queue[90000];
int visit[300][300];
point dir[8] = { { 1, 2 }, { 2, 1 }, { 1, -2 }, { 2, -1 }, { -1, 2 }, { -2, 1 }, {-1,-2},{-2,-1} };

int bfs(point& start, point& end, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			visit[i][j] = 0;
	}

	int front = 0, rear = -1;

	queue[++rear] = start;
	visit[start.x][start.y] = 1;

	int move = -1;
	while (front <= rear)
	{
		move++;
		int size = rear - front + 1;

		for (int i = 0; i < size; i++)
		{
			point cur = queue[front++];

			if (cur.x == end.x && cur.y == end.y)
				return move;

			for (int j = 0; j < 8; j++)
			{
				int x = cur.x + dir[j].x;
				int y = cur.y + dir[j].y;

				if (0 <= x && x < n && 0 <= y && y < n && !visit[x][y])
				{
					queue[++rear].x = x;
					queue[rear].y = y;
					visit[x][y] = 1;
				}
			}
		}
	}

	return -1;
}
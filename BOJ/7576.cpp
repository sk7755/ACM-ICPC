#include <cstdio>

struct point
{
	int r, c;
};

int main()
{
	int i, j;
	int m, n;
	int box[1000][1000];

	scanf("%d %d", &m, &n);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			scanf("%d", &box[i][j]);
	}

	point queue[1000000];
	int front = 0, rear = -1;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (box[i][j] == 1)
			{
				queue[++rear].r = i;
				queue[rear].c = j;
			}
		}
	}

	point dir[4] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

	int day = -1;
	int size;
	int x, y;
	point cur;
	while (front <= rear)
	{
		size = rear - front + 1;
		day++;
		while (size--)
		{
			cur = queue[front++];

			for (i = 0; i < 4; i++)
			{
				x = cur.r + dir[i].r;
				y = cur.c + dir[i].c;

				if (0 <= x && x < n && 0 <= y && y < m)
				{
					if (box[x][y] == 0)
					{
						queue[++rear].r = x;
						queue[rear].c = y;
						box[x][y] = 1;
					}
				}
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (box[i][j] == 0)
			{
				printf("-1\n");
				return 0;
			}
		}
	}

	printf("%d\n", day);

	return 0;
}
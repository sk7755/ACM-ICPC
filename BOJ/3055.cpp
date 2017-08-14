#include <cstdio>

struct point
{
	int x, y;
};

int main()
{
	char map[52][52] = { 0, };

	int r, c;

	scanf("%d %d", &r, &c);

	for (int i = 1; i <= r; i++)
		scanf("%s", map[i]+1);

	int dir[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, {0,-1} };

	int visit[52][52] = { 0, };
	point queue_s[2500];
	point queue_w[2500];
	int front_s = 0, rear_s = -1;
	int front_w = 0, rear_w = -1;

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (map[i][j] == '*')
				queue_w[++rear_w] = { i, j }, visit[i][j] = 1;
			if (map[i][j] == 'S')
				queue_s[++rear_s] = { i, j }, visit[i][j] = 1;
		}
	}
	int move = -1;
	while (front_s <= rear_s)
	{
		move++;

		int size = rear_w - front_w + 1;

		for (int i = 0; i < size; i++)
		{
			point cur = queue_w[front_w++];

			for (int j = 0; j < 4; j++)
			{
				int x = cur.x + dir[j][0];
				int y = cur.y + dir[j][1];

				if (map[x][y] == '.' && !visit[x][y])
					queue_w[++rear_w] = { x, y }, visit[x][y] = 1;
			}
		}

		size = rear_s - front_s + 1;

		for (int i = 0; i < size; i++)
		{
			point cur = queue_s[front_s++];

			if (map[cur.x][cur.y] == 'D')
			{

				printf("%d\n", move);
				return 0;
			}

			for (int j = 0; j < 4; j++)
			{
				int x = cur.x + dir[j][0];
				int y = cur.y + dir[j][1];

				if ((map[x][y] == '.' || map[x][y] == 'D') && !visit[x][y])
					queue_s[++rear_s] = { x, y }, visit[x][y] = 1;
			}
		}
	}

	printf("KAKTUS\n");

	return 0;
}

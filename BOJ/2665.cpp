#include <cstdio>

struct point
{
	int x, y;
};

int main()
{
	char map[52][52] = { 0, };
	int visit[52][52] = { 0, };
	point queue[2500];
	int front = 0, rear = -1;
	point dir[4] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, {0,-1} };
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%s", map[i] + 1);

	int del = -1;

	point tmp[2500];
	tmp[0] = { 1, 1 };
	visit[1][1] = 1;
	int tmp_k = 1;

	while (true)
	{
		del++;

		for (int i = 0; i < tmp_k; i++)
			queue[++rear] = tmp[i];
		tmp_k = 0;

		while (front <= rear)
		{
			point cur = queue[front++];

			if (cur.x == n && cur.y == n)
			{
				printf("%d\n", del);
				return 0;
			}

			for (int i = 0; i < 4; i++)
			{
				int x = cur.x + dir[i].x;
				int y = cur.y + dir[i].y;

				if (!visit[x][y])
				{
					if (map[x][y] == '1')
					{
						queue[++rear] = { x, y };
					}
					else if (map[x][y] == '0')
					{
						tmp[tmp_k++] = { x, y };
					}
					visit[x][y] = 1;
				}
			}
		}
	}

	return 0;
}
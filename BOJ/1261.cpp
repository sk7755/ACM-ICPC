#include <cstdio>

struct point
{
	int x, y;
};

int main()
{
	int n, m;
	char map[102][102] = { 0, };
	int visit[102][102] = { 0, };
	scanf("%d %d", &m, &n);
	
	for (int i = 1; i <= n; i++)
		scanf("%s", map[i] + 1);

	point queue[10000];
	point tmp[10000];
	int k = 0;
	int front = 0, rear = -1;
	point dir[4] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

	queue[++rear] = { 1, 1 };
	visit[1][1] = 1;

	int ans = -1;
	while (true)
	{
		ans++;
		k = 0;
		while (front <= rear)
		{
			point cur = queue[front++];

			if (cur.x == n && cur.y == m)
			{
				printf("%d\n", ans);
				return 0;
			}

			for (int i = 0; i < 4; i++)
			{
				int x = cur.x + dir[i].x;
				int y = cur.y + dir[i].y;

				if (!visit[x][y])
				{
					if (map[x][y] == '0')
					{
						queue[++rear] = { x, y };
						visit[x][y] = 1;
					}
					else if (map[x][y] == '1')
					{
						tmp[k++] = { x, y };
						visit[x][y] = 1;
					}
				}
			}
		}
		front = 0, rear = -1;
		for (int i = 0; i < k; i++)
			queue[++rear] = tmp[i];
	}
}
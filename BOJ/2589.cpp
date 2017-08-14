#include <cstdio>

int bfs(int start_x, int start_y);

class point
{
public:
	int x, y;

	point(int x = 0, int y = 0) :x(x), y(y) {}
};

int map[52][52] = { 0, };
int visit[52][52] = { 0, };
int n, m;

int main()
{

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		char str[52];
		scanf("%s", str+1);

		for (int j = 1; j <= m; j++)
		{
			if (str[j] == 'W')
				map[i][j] = 0;
			else
				map[i][j] = 1;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j])
			{
				if ((!map[i][j - 1] && !map[i][j + 1]) || (!map[i - 1][j] && !map[i + 1][j]))
				{
					int dist = bfs(i, j);
					if (ans < dist)
						ans = dist;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

point queue[2500];
point dir[4] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, {0,-1} };

//x.y로 부터 가장 긴 최단거리를 구하는 함수
int bfs(int start_x, int start_y)
{
	int front = 0, rear = -1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			visit[i][j] = 0;
	}

	queue[++rear].x = start_x;
	queue[rear].y = start_y;

	int dist = -1;

	while (front <= rear)
	{
		int size = rear - front + 1;
		dist++;
		for (int i = 0; i < size; i++)
		{
			point cur = queue[front++];

			for (int j = 0; j < 4; j++)
			{
				int x = cur.x + dir[j].x;
				int y = cur.y + dir[j].y;

				if (map[x][y] && !visit[x][y])
				{
					queue[++rear].x = x;
					queue[rear].y = y;
					visit[x][y] = 1;
				}
			}
		}
	}

	return dist;
}
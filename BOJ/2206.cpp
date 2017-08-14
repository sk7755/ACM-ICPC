#include <cstdio>
#include <queue>
using namespace std;

struct point
{
	int x, y;
	bool flag;

	point(int x, int y, int flag) : x(x), y(y), flag(flag){}
};

int bfs(point start, point end);

char map[1002][1002] = { 0, };
int dir[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
bool visit1[1002][1002] = { 0, };
bool visit2[1002][1002] = { 0, };

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
		scanf("%s", map[i] + 1);

	printf("%d\n", bfs({ 1, 1, 0 }, { n, m, 0 }));

	
	return 0;
}
queue<point> q;

int bfs(point start, point end)
{
	int front = 0, rear = -1;

	//flag 0은 하나도 벽을 부수지 않은 애
	q.push(start);
	visit1[1][1] = 1;
	int move = 0;
	while (!q.empty())
	{
		move++;
		int size = q.size();

		for (int i = 0; i < size; i++)
		{
			point cur = q.front();
			q.pop();

			if (cur.x == end.x && cur.y == end.y)
				return move;

			for (int j = 0; j < 4; j++)
			{
				int x = cur.x + dir[j][0];
				int y = cur.y + dir[j][1];

				if (map[x][y] == '1')
				{
					if (!visit2[x][y] && !cur.flag)
					{
						q.push({ x, y, 1 });
						visit2[x][y] = 1;
					}
				}
				else if (map[x][y] == '0')
				{
					if (cur.flag && !visit2[x][y])
					{
						q.push({ x, y, 1 });
						visit2[x][y] = 1;
					}
					
					if (!cur.flag && !visit1[x][y])
					{
						q.push({ x, y, 0 });
						visit1[x][y] = 1;
					}
				}
			}
		}
	}

	return -1;
}
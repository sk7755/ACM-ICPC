#include <cstdio>

class point
{
public:
	int x, y;

	point(int x = 0, int y = 0) :x(x), y(y) {}
};

int dfs(int x, int y);

char map[22][22] = { 0, };
int visit[22][22] = { 0, };

int main()
{
	int r, c;

	scanf("%d %d", &r, &c);

	for (int i = 1; i <= r; i++)
	{
		getchar();
		scanf("%s", map[i] + 1);
	}

	for (int i = 0; i <= r + 1; i++)
	{
		for (int j = 0; j <= c + 1; j++)
		{
			if (i == 0 || i == r + 1 || j == 0 || j == c + 1)
				visit[i][j] = 1;
		}
	}

	printf("%d\n", dfs(1, 1));

	return 0;
}

point dir[4] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
int alphabet[26] = { 0, };

int dfs(int x, int y)
{
	alphabet[map[x][y] - 'A'] = 1;
	visit[x][y] = 1;
	int max = 0;

	for (int i = 0; i < 4; i++)
	{
		int next_x = x + dir[i].x;
		int next_y = y + dir[i].y;

		if (!visit[next_x][next_y])
		{
			if (!alphabet[map[next_x][next_y] - 'A'])
			{
				int temp = dfs(next_x, next_y);

				alphabet[map[next_x][next_y] - 'A'] = 0;
				visit[next_x][next_y] = 0;
				if (temp > max)
					max = temp;
			}
		}
	}

	return max + 1;
}
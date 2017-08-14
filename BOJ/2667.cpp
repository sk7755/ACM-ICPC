#include <cstdio>

class point
{
public:
	int r, c;

	point(int r=0, int c=0) : r(r), c(c) {}
};

int dfs(int map[][27], int n, int r, int c);

int main()
{
	int map[27][27] = { 0, };
	int a[626] = { 0, };
	int b = 0;
	int n;

	scanf("%d", &n);

	char buf[27];

	for (int i = 1; i <= n; i++)
	{
		scanf("%s", buf);

		for (int j = 1; j <= n; j++)
			map[i][j] = buf[j - 1] - '0';
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j])
			{
				a[dfs(map, n, i,j)]++;
				b++;
			}
		}
	}

	printf("%d\n", b);

	for (int i = 1; i <= 625; i++)
	{
		if (a[i])
		{
			for (int j = 0; j < a[i]; j++)
				printf("%d\n", i);
		}
	}

	return 0;
}

point stack[625];
point dir[4] = { { 0, 1 }, { 1, 0 }, {-1, 0 }, { 0, -1 } };
int top;

//탐색하여 탐색한 곳은 0으로 바꾸어 두는 함수, 탐색한 곳의 수를 반환
int dfs(int map[][27], int n, int r, int c)
{
	top = -1;
	int m = 0;

	stack[++top] = point(r,c);
	map[r][c] = 0;
	m++;

	while (top >= 0)
	{
		r = stack[top].r;
		c = stack[top].c;

		int i;
		for (i = 0; i < 4; i++)
		{
			if (map[r + dir[i].r][c+dir[i].c])
			{
				stack[++top] = point(r + dir[i].r, c+dir[i].c);
				map[r + dir[i].r][c + dir[i].c] = 0;
				m++;
				break;
			}
		}

		if (i == 4)
			top--;
	}

	return m;
}

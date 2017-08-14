#include <cstdio>

int paper[129][129] = { 0, };
int white = 0, blue = 0;
void dq(int sx, int sy, int size)
{
	int tmp = paper[sx + size - 1][sy + size - 1] - paper[sx - 1][sy + size - 1] - paper[sx + size - 1][sy - 1] + paper[sx - 1][sy - 1];

	if (tmp == 0)
	{
		white++;
		return;
	}

	if (tmp == size*size)
	{
		blue++;
		return;
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			dq(sx + (size/2 * i), sy + (size/2 * j), size / 2);
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int tmp;
			scanf("%d", &tmp);
			paper[i][j] = paper[i][j - 1] + paper[i - 1][j] - paper[i - 1][j - 1] + tmp;
		}
	}

	dq(1, 1, n);
	printf("%d\n%d\n",white,blue );
}
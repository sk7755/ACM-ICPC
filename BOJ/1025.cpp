#include <cstdio>
#include <cmath>

int isPower(int a);
void solve(int num, int x, int y, int r, int c);

int ans = -1;
char a[9][9];
int n, m;

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		scanf("%s", a[i]);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (isPower(a[i][j] -'0') && a[i][j] - '0' > ans)
				ans = a[i][j] - '0';

			for (int ii = 0; ii < n; ii++)
			{
				for (int jj = 0; jj < m; jj++)
				{
					if (i != ii || j != jj)
					{
						solve(a[ii][jj] - '0' + (a[i][j] - '0') * 10, ii, jj, ii - i, jj - j);
					}
				}
			}
		}
	}
	printf("%d\n", ans);
}

int isPower(int a)
{
	int r = sqrt(a);

	return r*r == a ? 1 : 0;
}

void solve(int num, int x, int y, int r, int c)
{
	if (isPower(num) && num > ans)
		ans = num;

	if (0 <= x + r && x + r < n && 0 <= y + c && y + c < m)
		solve(num * 10 + a[x + r][y + c] - '0', x + r, y + c, r, c);

	return;
}
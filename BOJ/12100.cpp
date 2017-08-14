#include <cstdio>

void game(int n, int cube[20][20], int m);
void move(int n, int cube[20][20]);

int ans = 0;

int main()
{
	int n;
	scanf("%d", &n);

	int cube[20][20];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &cube[i][j]);
		}
	}
	game(n, cube, 0);

	printf("%d\n", ans);
}

void game(int n, int cube[20][20], int m)
{
	if (m == 5)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (cube[i][j] > ans)
					ans = cube[i][j];
			}
		}
		return;
	}

	int Lcube[20][20],Rcube[20][20], Ucube[20][20], Dcube[20][20];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Lcube[i][j] = cube[i][j];
			Rcube[i][j] = cube[i][n - 1 - j];
			Ucube[i][j] = cube[j][i];
			Dcube[i][j] = cube[n - 1 - j][i];
		}
	}
	move(n, Lcube);
	move(n, Rcube);
	move(n, Ucube);
	move(n, Dcube);
	game(n, Lcube, m + 1);
	game(n, Rcube, m + 1);
	game(n, Ucube, m + 1);
	game(n, Dcube, m + 1);

	return;
}

void move(int n, int cube[20][20])
{
	for (int i = 0; i < n; i++)
	{
		int pre = -1;
		int flag = 1;
		for (int j = 0; j < n; j++)
		{
			if (cube[i][j])
			{
				int tmp = cube[i][j];
				cube[i][j] = 0;
				if (!flag && tmp == cube[i][pre])
				{
					//합쳐지는 경우
					cube[i][pre] *= 2;
					flag = 1;
				}
				else
				{
					//합쳐지지 않는 경우
					cube[i][pre + 1] = tmp;
					flag = 0;
					pre++;
				}
			}
		}
	}
}
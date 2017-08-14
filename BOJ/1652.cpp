#include <cstdio>

int main()
{
	char map[102][102] = { 0, };

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%s", map[i] + 1);

	int row = 0, col = 0;
	for (int i = 1; i <= n; i++)
	{
		int tmp = 0;
		for (int j = 1; j <= n+1; j++)
		{
			if (map[i][j] != '.')
			{
				if (tmp >= 2)
					row++;
				tmp = 0;
			}
			else
			{
				tmp++;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int tmp = 0;
		for (int j = 1; j <= n+1; j++)
		{
			if (map[j][i] != '.')
			{
				if (tmp >= 2)
					col++;
				tmp = 0;
			}
			else
			{
				tmp++;
			}
		}
	}

	printf("%d %d\n", row, col);

	return 0;
}
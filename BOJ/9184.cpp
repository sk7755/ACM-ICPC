#include <cstdio>

int main()
{
	int w[21][21][21] = { 0, };

	for (int i = 0; i <= 20; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			w[0][i][j] = w[i][0][j] = w[i][j][0] = 1;
		}
	}

	for (int i = 1; i <= 20; i++)
	{
		for (int j = 1; j <= 20; j++)
		{
			for (int k = 1; k <= 20; k++)
			{
				if (i < j && j < k)
					w[i][j][k] = w[i][j][k - 1] + w[i][j - 1][k - 1] - w[i][j - 1][k];
				else
					w[i][j][k] = w[i - 1][j][k] + w[i - 1][j - 1][k] + w[i - 1][j][k - 1] - w[i - 1][j - 1][k - 1];
			}
		}
	}

	while (true)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == -1 && b == -1 && c == -1)
			return 0;

		printf("w(%d, %d, %d) = ", a, b, c);

		if (a <= 0 || b <= 0 || c <= 0)
			a = b = c = 0;
		else if (a > 20 || b > 20 || c > 20)
			a = b = c = 20;

		printf("%d\n", w[a][b][c]);
	}
}
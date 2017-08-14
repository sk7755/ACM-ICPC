#include <cstdio>

int main()
{
	int g1[100][100] = { 0, };
	int g2[100][100] = { 0, };

	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);

		g1[u-1][v-1] = 1;
		g2[v-1][u-1] = 1;
	}

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (g1[i][k] && g1[k][j])
					g1[i][j] = 1;
				if (g2[i][k] && g2[k][j])
					g2[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		int k = 0;
		for (int j = 0; j < n; j++)
		{
			if (g1[i][j])
				k++;
			if (g2[i][j])
				k++;
		}

		printf("%d\n", n - k - 1);
	}

	return 0;
}
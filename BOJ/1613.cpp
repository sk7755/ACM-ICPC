#include <cstdio>

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	int g[401][401] = { 0, };

	for (int i = 0; i < k; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		g[u][v] = 1;
		g[v][u] = -1;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (g[i][k] == 1 && g[k][j] == 1)
					g[i][j] = 1;
				if (g[i][k] == -1 && g[k][j] == -1)
					g[i][j] = -1;
			}
		}
	}

	int s;
	scanf("%d", &s);

	for (int i = 0; i < s; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		printf("%d\n", g[v][u]);
	}
}
#include <cstdio>

enum{ INF = 1000000000};

int main()
{
	int n, e;
	scanf("%d %d", &n, &e);

	int dist[401][401];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			dist[i][j] = INF;
	}

	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		dist[u][v] = w;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	int min = INF;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (min > dist[i][j] + dist[j][i])
				min = dist[i][j] + dist[j][i];
		}
	}

	if (min == INF)
		printf("-1\n");
	else
		printf("%d\n", min);

	return 0;
}
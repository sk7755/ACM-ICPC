#include <cstdio>

enum{INF = 1000000000};

int main()
{
	int n;
	int graph[101][101] = { 0, };
	scanf("%d", &n);

	int m;
	scanf("%d", &m);

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			graph[i][j] = INF;
		}
		graph[i][i] = 0;
	}

	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		if (graph[u][v] > w)
			graph[u][v] = w;
	}


	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (graph[i][j] > graph[i][k] + graph[k][j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}
			
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (graph[i][j] == INF)
				printf("0 ");
			else
				printf("%d ", graph[i][j]);
		}
		printf("\n");
	}


	return 0;
}
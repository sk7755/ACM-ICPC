#include <cstdio>

int n;
int g[16][16];
int visit[16] = { 0, };
int ans = 100000000;

void dfs(int v, int move, int w);

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			scanf("%d", &g[i][j]);
	}

	for (int i = 0; i < n; i++)
	{
		if (g[0][i])
			dfs(i, 1, g[0][i]);
	}
	printf("%d\n", ans);
	return 0;
}

void dfs(int v, int move, int w)
{
	if (v == 0)
	{
		if (move == n)
		{
			if (ans > w)
				ans = w;
		}
		return;
	}

	visit[v] = 1;

	for (int i = 0; i < n; i++)
	{
		if (!visit[i] && g[v][i])
			dfs(i, move + 1, w + g[v][i]);
	}
	visit[v] = 0;

}
#include <cstdio>

int visit[100001];
int g[100001];
int ans = 0;
int dfs(int v);

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n;
		scanf("%d", &n);

		for (int i = 1; i <= n; i++)
			visit[i] = 0;

		for (int i = 1; i <= n; i++)
			scanf("%d", &g[i]);

		ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (!visit[i])
				dfs(i);
		}
		printf("%d\n", ans);

	}
}

int dfs(int v)
{
	visit[v] = 1;

	if (visit[g[v]] == 1)
	{
		visit[v] = -1;
		if (v == g[v])
			return -1;
		else
			return g[v];
	}
	else if (visit[g[v]] == -1)
	{
		visit[v] = -1;
		ans++;
		return -1;
	}
	else
	{
		int tmp = dfs(g[v]);
		visit[v] = -1;
		if (tmp == -1)
		{
			ans++;
			return -1;
		}
		else if (tmp == v)
			return -1;
		else
			return tmp;
	}
}
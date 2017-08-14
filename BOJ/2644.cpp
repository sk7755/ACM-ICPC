#include <cstdio>

int g[101][101] = { 0, };
int visit[101] = { 0, };
int n;
int end;

int dfs(int v);

int main()
{
	scanf("%d", &n);
	int start;
	scanf("%d %d", &start, &end);
	int m;
	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		g[u][v] = g[v][u] = 1;
	}

	int ans = dfs(start);

	printf("%d\n", ans-1);
}
//dfs해도 상관없는 이유는 갈 수 있는 길이 오직 하나라서
int dfs(int v)
{
	visit[v] = 1;

	if (v == end)	//성공
		return 1;

	for (int i = 1; i <= n; i++)
	{
		if (g[v][i] && !visit[i])
		{
			int temp = dfs(i);
			if (temp)
				return temp + 1;
		}
	}
	//실패
	return 0;
}
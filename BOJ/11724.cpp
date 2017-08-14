#include <cstdio>
#include <cstdlib>

typedef struct node* nptr;

struct node
{
	int v;
	nptr link;
};


nptr head[1001] = { 0, };
int visit[1001] = { 0, };

void insert(int u, int v)
{
	nptr pnew = (nptr)malloc(sizeof(node));
	pnew->v = v;
	pnew->link = head[u];
	head[u] = pnew;
}

void dfs(int v)
{
	visit[v] = 1;
	
	for (nptr p = head[v]; p; p = p->link)
	{
		if (!visit[p->v])
			dfs(p->v);
	}
}

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		insert(u, v);
		insert(v, u);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!visit[i])
		{
			dfs(i);
			ans++;
		}
	}
	printf("%d\n", ans);
}
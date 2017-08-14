#include <cstdio>

typedef struct node* nptr;

struct node
{
	int v;
	nptr link;
};

nptr head[100001] = { 0, };
int visit[100001] = { 0, };

void insert(int u, int v)
{
	nptr pnew = new node;
	pnew->v = v;
	pnew->link = head[u];
	head[u] = pnew;
}

void dfs(int v);

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		insert(u, v);
		insert(v, u);
	}
	visit[1] = 1;
	dfs(1);

	for (int i = 2; i <= n; i++)
		printf("%d\n", visit[i]);

	return 0;
}

void dfs(int cur)
{
	for (nptr p = head[cur]; p; p = p->link)
	{
		if (!visit[p->v])
		{
			visit[p->v] = cur;
			dfs(p->v);
		}
	}
}
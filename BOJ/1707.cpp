#include <cstdio>
#include <cstdlib>

typedef struct node* nptr;

struct node
{
	int v;
	nptr link;
};

nptr head[20001];
int visit[20001];

int dfs(int v, int t);

void insert(int u, int v)
{
	nptr pnew = (nptr)malloc(sizeof(node));
	pnew->v = v;
	pnew->link = head[u];
	head[u] = pnew;
}

int main()
{
	int t;

	scanf("%d", &t);

	while (t--)
	{
		int n, e;

		scanf("%d %d", &n, &e);

		for (int i = 1; i <= n; i++)
			head[i] = NULL,visit[i] = 0;

		for (int i = 0; i < e; i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			insert(u, v);
			insert(v, u);
		}
		int success = 1;
		for (int i = 1; i <= n; i++)
		{
			if (!visit[i])
				success &= dfs(i, 1);
		}

		if (success)
			printf("YES\n");
		else
			printf("NO\n");

	}

	return 0;
}

int dfs(int v, int t)
{
	visit[v] = t;
	int ret = 1;

	for (nptr p = head[v]; p; p = p->link)
	{
		if (!visit[p->v])
			ret &= dfs(p->v, -t);
		else if (visit[p->v] != -t)
			ret = 0;
	}

	return ret;
}
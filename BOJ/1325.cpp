#include <cstdio>
#include <cstdlib>

int dfs(int v);

typedef struct node* nptr;

struct node
{
	int v;
	nptr link;
};

nptr head[10001] = { 0, };
int visit[10001];
int flag[10001] = { 0, };
int n;

int main()
{
	int m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d %d", &v, &u);
		nptr pnew = (nptr)malloc(sizeof(node));
		pnew->v = v;
		pnew->link = head[u];
		head[u] = pnew;
	}

	int ans[10000];
	int k = 0;
	int max = 0;

	for (int i = 1; i <= n; i++)
	{
		if (!flag[i])
		{
			for (int j = 1; j <= n; j++)
				visit[j] = 0;
			visit[i] = 2;
			int tmp = dfs(i);

			for (int j = 1; j <= n; j++)
			{
				if (visit[j] == 1)
					flag[j] = 1;
				else if (visit[j] == 2)
					flag[j] = tmp;
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (flag[i] > max)
		{
			k = 0;
			ans[k++] = i;
			max = flag[i];
		}
		else if (flag[i] == max)
			ans[k++] = i;
	}

	for (int i = 0; i < k; i++)
		printf("%d ", ans[i]);
	return 0;
}

int dfs(int v)
{
	int ret = 1;

	for (nptr p = head[v]; p; p = p->link)
	{
		if (!visit[p->v])
		{
			visit[p->v] = 1;
			ret += dfs(p->v);
		}
	}

	for (nptr p = head[v]; p; p = p->link)
	{
		if (visit[p->v] == 2)
		{
			visit[v] = 2;
			break;
		}
	}

	return ret;
}
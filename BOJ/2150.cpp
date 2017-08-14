#include <cstdio>

typedef struct node* nptr;

struct node
{
	int v;
	nptr link;
};

nptr head[10001] = { 0, };

int main()
{
	int v, e;

	scanf("%d %d", &v, &e);

	for (int i = 0; i < e; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);

		nptr pnew = new node;
		pnew->v = v;
		pnew->link = head[u];
		head[u] = pnew;
	}
}
 
int dfs(int v)
{
	fg
}
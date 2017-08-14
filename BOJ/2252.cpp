#include <cstdio>

typedef struct node* nptr;

struct node
{
	int v;
	nptr link;
};

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	nptr head[32001] = { 0, };
	int indegree[32001] = { 0, };

	for (int i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);

		nptr pnew = new node;
		pnew->v = v;
		pnew->link = head[u];
		head[u] = pnew;
		indegree[v]++;
	}

	int queue[32000];
	int front = 0, rear = -1;

	for (int i = 1; i <= n; i++)
	{
		if (!indegree[i])
			queue[++rear] = i;
	}

	while (front <= rear)
	{
		int cur = queue[front++];
		printf("%d ", cur);
		for (nptr p = head[cur]; p; p = p->link)
		{
			indegree[p->v]--;
			if (!indegree[p->v])
				queue[++rear] = p->v;
		}
	}
	printf("\n");


	return 0;
}
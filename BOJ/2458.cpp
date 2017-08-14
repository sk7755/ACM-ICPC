#include <cstdio>

typedef struct node* nptr;

struct node
{
	int v;
	nptr link;
};

void insert(nptr head[], int u, int v)
{
	nptr pnew = new node;
	pnew->v = v;
	pnew->link = head[u];
	head[u] = pnew;
}

void bfs(nptr head[], int parent[],int cnt[] , int n)
{
	int queue[500];
	int front = 0, rear = -1;

	for (int i = 1; i <= n; i++)
	{
		if (!parent[i])
			queue[++rear] = i;
	}

	while (front <= rear)
	{
		int size = rear - front + 1;

		if (size == 1)
			cnt[queue[front]] += n - front - 1;

		for (int i = 0; i < size; i++)
		{
			int cur = queue[front++];

			for (nptr p = head[cur]; p; p = p->link)
			{
				parent[p->v]--;
				if (!parent[p->v])
					queue[++rear] = p->v;
			}
		}
	}
}

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);

	nptr head1[501] = { 0, };
	nptr head2[501] = { 0, };

	int parent1[501] = { 0, };
	int parent2[501] = { 0, };

	for (int i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		parent1[v]++;
		insert(head1,u, v);
		parent2[u]++;
		insert(head2, v, u);
	}
	int cnt[501] = { 0, };
	bfs(head1, parent1, cnt, n);
	bfs(head2, parent2, cnt, n);

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (cnt[i] == n - 1)
			ans++;
	}

	printf("%d\n", ans);

	return 0;
}

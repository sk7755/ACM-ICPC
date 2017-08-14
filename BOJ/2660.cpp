#include <cstdio>
#include <cstdlib>

typedef struct node* nptr;

struct node
{
	int v;
	nptr link;
};

void insert(int u, int v);
int bfs(int start);

nptr head[51] = { 0, };
int queue[50];
int visit[51];

int main()
{
	int n;

	scanf("%d", &n);

	while (true)
	{
		int u, v;
		scanf("%d %d", &u, &v);

		if (u == -1 && v == -1)
			break;

		insert(u, v);
		insert(v, u);
	}

	int ans[50];
	int k = 0;
	int min = 100000;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			visit[j] = 0;
		int tmp = bfs(i);

		if (tmp < min)
		{
			k = 0;
			ans[k++] = i;
			min = tmp;
		}
		else if (tmp == min)
			ans[k++] = i;
	}

	printf("%d %d\n", min, k);

	for (int i = 0; i < k; i++)
		printf("%d ", ans[i]);

	return 0;
}

int bfs(int start)
{
	int front = 0, rear = -1;
	queue[++rear] = start;
	visit[start] = 1;

	int move = -1;
	while (front <= rear)
	{
		move++;
		int size = rear - front + 1;

		for (int i = 0; i < size; i++)
		{
			int cur = queue[front++];

			for (nptr p = head[cur]; p; p = p->link)
			{
				if (!visit[p->v])
					queue[++rear] = p->v, visit[p->v] = 1;
			}
		}
	}

	return move;
}

void insert(int u, int v)
{
	nptr pnew = (nptr)malloc(sizeof(node));
	pnew->v = v;
	pnew->link = head[u];
	head[u] = pnew;
}
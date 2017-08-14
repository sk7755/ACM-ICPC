#include <cstdio>

int heap[32001];
int heap_size = 0;
void push(int key)
{
	int i = ++heap_size;
	while (i > 1 && heap[i / 2] > key)
	{
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = key;
}

int pop()
{
	int min = heap[1];
	heap[1] = heap[heap_size--];
	int i = 1;
	int smallest;

	while (true)
	{
		if (2 * i <= heap_size && heap[2 * i] < heap[i])
			smallest = 2 * i;
		else
			smallest = i;

		if (2 * i + 1 <= heap_size && heap[2 * i + 1] < heap[smallest])
			smallest = 2 * i + 1;

		if (smallest == i)
			break;

		int tmp = heap[smallest];
		heap[smallest] = heap[i];
		heap[i] = tmp;
		i = smallest;
	}

	return min;
}

typedef struct node* nptr;

struct node{
	int v;
	nptr link;
};

nptr head[32001] = { 0, };

int main()
{
	int n, m;
	int cnt[32001] = { 0, };
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		cnt[v]++;

		nptr pnew = new node;
		pnew->v = v;
		pnew->link = head[u];
		head[u] = pnew;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!cnt[i])
			push(i);
	}

	while (heap_size)
	{
		int cur = pop();
		printf("%d ", cur);

		for (nptr p = head[cur]; p; p = p->link)
		{
			cnt[p->v]--;

			if (!cnt[p->v])
				push(p->v);
		}
	}
}
#include <cstdio>

typedef class node* nptr;

class node
{
public:
	int v;
	int w;
	nptr link;

	node(int v, int w, nptr link) : v(v), w(w), link(link) {}
};

class graph
{
public:
	int n;
	nptr* head;

	graph(int n) : n(n)
	{
		head = new nptr[n + 1];
		for (int i = 1; i <= n; i++)
			head[i] = NULL;
	}

	void insert(int u, int v, int w)
	{
		head[u] = new node(v, w, head[u]);
	}
};

class min_heap
{
public:
	nptr* heap;
	int n;

	min_heap(int size) : n(0)
	{
		heap = new nptr[size + 1];
		heap[0] = new node(0, 0, 0);
	}

	void insert_heap(nptr element)
	{
		int i = ++n;
		while (element->w < heap[i / 2]->w)
		{
			heap[i] = heap[i / 2];
			i /= 2;
		}
		heap[i] = element;
	}

	nptr delete_heap()
	{
		nptr del = heap[1];

		nptr temp = heap[n];
		if (n)
		{
			heap[n--] = NULL;
			//temp¶û
		}
		int i = 1;
		int next = 1;
		do
		{
			heap[i] = heap[next];
			i = next;

			int left = 2 * i;
			int right = 2 * i + 1;

			next = left;
			if (right <= n && heap[right]->w < heap[left]->w)
				next = right;

		} while (next <= n && heap[next]->w < temp->w);

		if (n)
			heap[i] = temp;

		return del;
	}
};

enum{INF = 200000};

int main()
{
	int n, m,start;
	scanf("%d %d %d", &n, &m, &start);


	int visit[20001] = { 0, };
	graph g(n);
	min_heap h(m);

	for (int i = 0; i < m; i++)
	{
		int u, v, w;

		scanf("%d %d %d", &u, &v, &w);
		g.insert(u, v, w);
	}

	int min[20001];

	for (int i = 1	; i <= n; i++)
		min[i] = INF;
	min[start] = 0;

	for (nptr p = g.head[start]; p; p = p->link)
	{
		h.insert_heap(new node(p->v, p->w + min[start], NULL));
	}
	visit[start] = 1;

	while (h.n)
	{
		nptr cur = h.delete_heap();

		if (!visit[cur->v])
		{
			if (min[cur->v] > cur->w)
				min[cur->v] = cur->w;

			for (nptr p = g.head[cur->v]; p; p = p->link)
			{
				if (!visit[p->v])
				{
					h.insert_heap(new node(p->v, p->w + min[cur->v], NULL));
				}
			}
		}
		visit[cur->v] = 1;

	}

	for (int i = 1; i <= n; i++)
	{
		if (min[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", min[i]);
	}

	return 0;
}
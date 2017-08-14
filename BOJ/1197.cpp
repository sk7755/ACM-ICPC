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
		heap[0] = new node(0, -1000000, 0);
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



int main()
{
	int n, m;
	scanf("%d %d", &n, &m);


	int visit[10001] = { 0, };
	graph g(n);
	min_heap h(m);

	for (int i = 0; i < m; i++)
	{
		int u, v, w;

		scanf("%d %d %d", &u, &v, &w);
		g.insert(u, v, w);
		g.insert(v, u, w);
	}

	int price = 0;

	for (nptr p = g.head[1]; p; p = p->link)
		h.insert_heap(p);
	visit[1] = 1;

	while (h.n)
	{
		nptr cur = h.delete_heap();

		if (!visit[cur->v])
		{
			price += cur->w;
			for (nptr p = g.head[cur->v]; p; p = p->link)
			{
				if (!visit[p->v])
					h.insert_heap(p);
			}
			visit[cur->v] = 1;
		}
	}

	printf("%d\n", price);

	return 0;
}
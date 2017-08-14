#include <cstdio>

typedef class node* nptr;

class node
{
public:
	int v,w;
	nptr link;

	node(int v,int w, nptr link) : v(v),w(w), link(link) {}
};

class graph
{
public:
	int n;
	nptr *head;
	int* visit;
	int* queue;

	graph(int n) :n(n)
	{
		head = new nptr[n + 1];
		for (int i = 1; i <= n; i++)
			head[i] = NULL;
		visit = new int[n + 1];
		queue = new int[n + 1];
	}

	void insert(int u, int v, int w)
	{
		head[u] = new node(v,w, head[u]);
	}

	int bfs(int start, int end, int m)
	{
		int front = 0, rear = -1;

		for (int i = 1; i <= n; i++)
			visit[i] = 0;

		queue[++rear] = start;
		visit[start] = 1;

		while (front <= rear)
		{
			int cur = queue[front++];

			if (cur == end)
				return 1;

			for (nptr p = head[cur]; p; p = p->link)
			{
				if (!visit[p->v] && m <= p->w)
				{
					queue[++rear] = p->v;
					visit[p->v] = 1;
				}
			}
		}
		return 0;
	}

	~graph()
	{
		delete[] visit;
		delete[] queue;
		
		for (int i = 1; i <= n; i++)
		{
			for (nptr p = head[i]; p;)
			{
				nptr del = p;
				p = p->link;
				delete del;
			}
		}
		delete[] head;
	}
};

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);

	graph g(n);

	int max = 0;
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		g.insert(u, v, w);
		g.insert(v, u, w);

		if (max < w)
			max = w;
	}
	int start, end;

	scanf("%d %d", &start, &end);

	int left = 1, right = max;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (g.bfs(start, end, mid))
			left = mid + 1;
		else
			right = mid - 1;
	}
	printf("%d\n", right);

	return 0;
}

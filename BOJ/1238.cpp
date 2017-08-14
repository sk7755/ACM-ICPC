#include <cstdio>

typedef class node* nptr;

class node
{
public:
	int v,w;
	nptr link;

	node(int v, int w, nptr link) :v(v), w(w), link(link) {}
};

class graph
{
public:
	int n;
	nptr *head;

	graph(int n) : n(n)
	{
		head = new nptr[n + 1];
		for (int i = 1; i <= n; i++)
		{
			head[i] = NULL;
		}
	}

	void insert(int u, int v, int w)
	{
		head[u] = new node(v, w, head[u]);
	}
};

enum{INF = 1000000};

int main()
{
	int n, m, x;

	scanf("%d %d %d", &n, &m, &x);

	graph g1(n) , g2(n);
	//g1이 x로 가는거 g2가 x에서 출발하는거

	for (int i = 0; i < m; i++)
	{
		int u, v, w;

		scanf("%d %d %d", &u, &v, &w);

		g1.insert(v, u, w);
		g2.insert(u, v, w);
	}

	int dist1[1001] = { 0, };
	int visit[1001] = { 0, };

	for (int i = 1; i <= n; i++)
		dist1[i] = INF;
	dist1[x] = 0;
	for (int k = 1; k <= n; k++)
	{
		int min = INF;
		int find = 0;
		for (int i = 1; i <= n; i++)
		{
			if (!visit[i])
			{
				if (min > dist1[i])
				{
					min = dist1[i];
					find = i;
				}
			}
		}

		visit[find] = 1;
		for (nptr p = g1.head[find]; p; p = p->link)
		{
			if (dist1[p->v] > dist1[find] + p->w)
				dist1[p->v] = dist1[find] + p->w;
		}
	}
	//여기서 부터 back하는거 계산
	int dist2[1001] = { 0, };

	for (int i = 1; i <= n; i++)
		dist2[i] = INF, visit[i] = 0;
	dist2[x] = 0;
	for (int k = 1; k <= n; k++)
	{
		int min = INF;
		int find = 0;
		for (int i = 1; i <= n; i++)
		{
			if (!visit[i])
			{
				if (min > dist2[i])
				{
					min = dist2[i];
					find = i;
				}
			}
		}

		visit[find] = 1;
		for (nptr p = g2.head[find]; p; p = p->link)
		{
			if (dist2[p->v] > dist2[find] + p->w)
				dist2[p->v] = dist2[find] + p->w;
		}
	}

	int max = 0;
	for (int i = 1; i <= n; i++)
	{
		if (max < dist1[i] + dist2[i])
			max = dist1[i] + dist2[i];
	}
	printf("%d\n", max);

	return 0;
}
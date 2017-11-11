#include <cstdio>

typedef struct NODE* nptr;

struct NODE
{
	int v;
	long long w;
	nptr link;
};

nptr head[100001] = { 0, };
int visit[100001] = { 0, };

enum { m = 1000000007, inverse = 500000004};

void insert(int u, int v, long long w)
{
	nptr pnew = new NODE;
	pnew->v = v;
	pnew->w = w;
	pnew->link = head[u];
	head[u] = pnew;
}

long long ans = 0;

long long dfs(int v)
{
	long long ret = 0;
	long long def = 0;
	visit[v] = 1;

	for (nptr p = head[v]; p; p = p->link)
	{
		if (!visit[p->v])
		{
			long long tmp = ((dfs(p->v) + 1) * (p->w)) % m;
			ret = (ret + tmp) % m;
			def = (def - tmp * tmp) % m;
		}
	}

	ans = ( ans + ((ret * ret + def) % m) * inverse) % m;
	ans = (ans + ret) % m;

	return ret;
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		long long w;
		scanf("%d %d %lld", &u, &v, &w);
		insert(u, v, w);
		insert(v, u, w);

	}
	dfs(1);
	if (ans < 0)
		ans += m;
	printf("%lld\n", ans);

	return 0;
}
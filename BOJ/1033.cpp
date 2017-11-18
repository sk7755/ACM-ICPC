#include <cstdio>

int n;
int g[10][10] = { 0, };
int ans[10] = { 0, };
int queue[10];

int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}

void bfs(int start, int c)
{
	int visit[10] = { 0, };
	int front = 0, rear = -1;

	queue[++rear] = start;
	visit[start] = 1;

	while (front <= rear)
	{
		int cur = queue[front++];
		ans[cur] *= c;

		for (int i = 0; i < n; i++)
		{
			if (g[cur][i] && !visit[i])
			{
				visit[i] = 1;
				queue[++rear] = i;
			}
		}
	}
}

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n - 1; i++)
	{
		int a, b, p, q;
		scanf("%d %d %d %d", &a, &b, &p, &q);

		if (ans[a] == 0 && ans[b] == 0)
		{
			ans[a] = p;
			ans[b] = q;
		}
		else if (ans[a] != 0 && ans[b] == 0)
		{
			q *= ans[a];
			bfs(a, p);
			ans[b] = q;
		}
		else if (ans[b] != 0 && ans[a] == 0)
		{
			p *= ans[b];
			bfs(b, q);
			ans[a] = p;
		}
		else
		{
			int tmp = ans[a];
			bfs(a, p*ans[b]);
			bfs(b, q*tmp);
		}

		g[a][b] = g[b][a] = 1;

	}

	int d = ans[0];
	for (int i = 1; i < n; i++)
		d = gcd(d, ans[i]);

	for (int i = 0; i < n; i++)
		printf("%d ", ans[i]/d);

	return 0;
}
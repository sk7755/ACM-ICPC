#include <cstdio>

typedef struct node* nptr;

struct node
{
	int v, w;
	nptr link;
};

nptr head[10001] = { 0, };

int ans = 0;
int solve(int v);

int main()
{
	int n;

	scanf("%d", &n);

	for (int i = 1; i< n; i++)
	{
		int u;
		nptr pnew = new node;

		scanf("%d %d %d", &u, &pnew->v, &pnew->w);
		pnew->link = head[u];
		head[u] = pnew;
	}

	solve(1);

	printf("%d\n", ans);

	return 0;
}

//중간 다리 역할을 할때 가장 큰 두개의 선을 골라 최댓값과 비교, 그리고 가장 큰 선의 w를 반환
int solve(int v)
{
	int first = 0, second = 0;

	for (nptr p = head[v]; p; p = p->link)
	{
		int value = solve(p->v) + p->w;

		if (value > first)
			second = first, first = value;
		else if (value > second)
			second = value;
	}

	if (first + second > ans)
		ans = first + second;

	return first;
}
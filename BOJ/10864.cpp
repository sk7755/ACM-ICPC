#include <cstdio>

int main()
{
	int n, m;
	int a[1001] = { 0, };
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int p, q;
		scanf("%d %d", &p, &q);

		a[p]++, a[q]++;
	}

	for (int i = 1; i <= n; i++)
		printf("%d\n", a[i]);

	return 0;
}
#include <cstdio>

int main()
{
	int n, m;
	int a[100000] = { 0, };

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		int temp;
		scanf("%d", &temp);

		a[i] = a[i - 1] + temp;
	}

	for (int i = 0; i < m; i++)
	{
		int l, r;
		scanf("%d %d", &l, &r);

		printf("%d\n", a[r] - a[l - 1]);
	}

	return 0;
}
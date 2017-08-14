#include <cstdio>

int main()
{
	int n, m;
	int a[101] = { 0, };
	scanf("%d %d", &n, &m);

	while (m--)
	{
		int i, j, k;

		scanf("%d %d %d", &i, &j, &k);

		while (i <= j)
			a[i++] = k;
	}

	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);

	return 0;
}
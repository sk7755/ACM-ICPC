#include <cstdio>

inline void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int n, m;
	int a[101];
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
		a[i] = i;
	for (int i = 0; i < m; i++)
	{
		int s, t;
		scanf("%d %d", &s, &t);
		swap(a[s], a[t]);
	}

	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);

	return 0;
}
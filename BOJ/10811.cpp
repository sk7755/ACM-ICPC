#include <cstdio>

inline void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int a[101];
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
		a[i] = i;

	while (m--)
	{
		int start, end;
		scanf("%d %d", &start, &end);

		for (int i = 0; i < (end - start + 1) / 2; i++)
			swap(a[start + i], a[end - i]);
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);

	return 0;
}
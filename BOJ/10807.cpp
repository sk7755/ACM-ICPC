#include <cstdio>

int main()
{
	int n;

	scanf("%d", &n);

	int a[201] = { 0, };

	int b;
	for (int i = 0; i < n; i++)
		scanf("%d", &b) , a[b+100]++;

	int v;
	scanf("%d", &v);

	printf("%d\n", a[v+100]);

	return 0;
}
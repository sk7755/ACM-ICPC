#include <cstdio>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	n--, m--;

	int i = n % 4 - m % 4;
	int j = n / 4 - m / 4;
	if (i < 0)
		i = -i;
	if (j < 0)
		j = -j;

	printf("%d\n", i + j);

	return 0;
}
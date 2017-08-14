#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	n -= 2;

	int t = n*(n + 1) / 2;
	t = t*(t-1) / 6;

	printf("%d\n", t);

	return 0;
}
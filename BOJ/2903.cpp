#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);

	printf("%d\n",(1 << (2 * n)) + (2 << n) + 1);

	return 0;
}
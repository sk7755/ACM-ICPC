#include <cstdio>

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b,&c);

	if (a + b < 2 * c)
		printf("%d\n", a + b);
	else
		printf("%d\n", a + b - 2 * c);

	return 0;
}
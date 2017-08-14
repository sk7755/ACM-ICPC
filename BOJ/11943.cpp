#include <cstdio>

int main()
{
	int a, b, c, d;

	scanf("%d %d %d %d", &a, &b, &c, &d);

	if (a + d < b + c)
		printf("%d\n", a + d);
	else
		printf("%d\n", b + c);

	return 0;
}
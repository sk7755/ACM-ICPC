#include <cstdio>

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	if (c % 2)
		printf("%d\n", a^b);
	else
		printf("%d\n", a);
}
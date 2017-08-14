#include <cstdio>

int main()
{
	int a, b, c, d, p;

	scanf("%d %d %d %d %d", &a, &b, &c, &d, &p);

	int x = p * a;
	int y = b;

	if (c < p)
		y += (p - c) * d;

	if (x < y)
		printf("%d\n", x);
	else
		printf("%d\n", y);

	return 0;
}
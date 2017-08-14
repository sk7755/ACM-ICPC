#include <cstdio>

int main()
{
	int a, b;

	scanf("%*d %d %d", &a, &b);

	int m = 0;
	while (a != b)
	{
		a = (a + 1) / 2;
		b = (b + 1) / 2;
		m++;
	}

	printf("%d\n", m);

	return 0;
}
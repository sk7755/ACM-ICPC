#include <cstdio>

int main()
{
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	int m = a * 3600 + b * 60 + c;

	int d;
	scanf("%d", &d);
	m += d;

	m %= 24 * 3600;

	printf("%d ", m / 3600);
	m %= 3600;
	printf("%d ", m / 60);
	printf("%d\n", m % 60);

	return 0;
	
}
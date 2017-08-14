#include <cstdio>

int main()
{
	int a, b, m;

	scanf("%d %d", &a, &b);

	m = a*b;

	for (int i = 0; i < 3; i++, b/=10)
	{
		printf("%d\n", a*(b % 10));
	}
	printf("%d\n", m);
}
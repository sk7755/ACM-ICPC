#include <cstdio>

int main()
{
	int n;

	scanf("%d", &n);

	int p1 = 100, p2 = 100;
	while (n--)
	{
		int a, b;

		scanf("%d %d", &a, &b);

		if (a > b)
			p2 -= a;
		else if (a < b)
			p1 -= b;
	}
	printf("%d\n%d\n", p1, p2);

	return 0;
}
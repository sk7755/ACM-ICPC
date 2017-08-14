#include <cstdio>

int main()
{
	int x;
	scanf("%d", &x);

	int n = 0;
	while (n*n + 3*n + 2 < (x << 1))
		n++;

	int a = x - (n*n + n) / 2 -1 ;
	n++;
	if (n % 2)
	{
		printf("%d/%d\n", n  - a, 1 + a);
	}
	else
	{
		printf("%d/%d\n", 1 + a, n - a );
	}

	return 0;
}
#include <cstdio>

int main()
{
	int n;

	scanf("%d", &n);

	int a = 0;
	while (n)
	{
		a += n / 5;
		n /= 5;
	}

	printf("%d\n", a);

	return 0;
}
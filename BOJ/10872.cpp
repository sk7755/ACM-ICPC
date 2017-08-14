#include <cstdio>

int main()
{
	int f = 1;
	int n;

	scanf("%d", &n);

	for (int i = 2; i <= n; i++)
	{
		f *= i;
	}

	printf("%d\n", f);

	return 0;
}
#include <cstdio>

int main()
{
	int n;

	scanf("%d", &n);

	while (true)
	{
		int a;

		scanf("%d", &a);

		if (a == 0)
			return 0;

		if (a%n)
			printf("%d is NOT a multiple of %d.\n",a,n);
		else
			printf("%d is a multiple of %d.\n", a, n);
	}

	return 0;
}
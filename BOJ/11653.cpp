#include <cstdio>

int main()
{
	int n;

	scanf("%d", &n);
	
	if (n == 1)
	{
		printf("1\n");
		return 0;
	}

	while (!(n % 2))
	{
		printf("2\n");
		n /= 2;
	}

	int i = 3;
	while (i*i<=n)
	{
		while (!(n%i))
		{
			printf("%d\n",i);
			n /= i;
		}
		i += 2;
	}

	if (n != 1)
		printf("%d\n", n);

	return 0;
}
#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);

	if (!(n % 2))
	{
		printf("%d\n",n / 2);
		return 0;
	}

	for (int i = 3; i*i <= n; i+=2)
	{
		if (!(n%i))
		{
			printf("%d\n", n - n / i);
			return 0;
		}
	}

	printf("%d\n", n - 1);

}
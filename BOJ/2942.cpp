#include <cstdio>

int gcd(int a, int b);

int main()
{
	int a, b;

	scanf("%d %d", &a, &b);
	int d = gcd(a, b);

	for (int i = 1; i <= d; i++)
	{
		if (!(d%i))
		{
			printf("%d %d %d\n", i, a / i, b / i);
		}
	}

	return 0;
	
}

int gcd(int a, int b)
{
	while (b)
	{
		int tmp = a%b;
		a = b;
		b = tmp;
	}

	return a;
}
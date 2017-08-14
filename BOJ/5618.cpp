#include <cstdio>

int gcd(int a, int b);

int main()
{
	int n;
	scanf("%d", &n);

	int d;
	scanf("%d", &d);
	for (int i = 1; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		d = gcd(d, tmp);
	}

	for (int i = 1; i <= d; i++)
	{
		if (!(d%i))
			printf("%d\n", i);
	}
	return 0;
}

int gcd(int a, int b)
{
	while (b)
	{
		a %= b;
		int tmp = a;
		a = b;
		b = tmp;
	}
	return a;
}

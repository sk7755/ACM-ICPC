#include <cstdio>

int gcd(int a, int b);

int main()
{
	int n;
	scanf("%d", &n);
	int denom, nom;

	scanf("%d", &denom);

	for (int i = 1; i < n; i++)
	{
		scanf("%d", &nom);

		int d = gcd(denom, nom);
		printf("%d/%d\n", denom / d, nom / d);
	}

	return 0;
}

int gcd(int a, int b)
{
	while (b)
	{
		int tmp = b;
		b = a % b;
		a = tmp;
	}

	return a;
}
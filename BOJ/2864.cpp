#include <cstdio>

int main()
{
	int a, b;

	scanf("%d %d", &a, &b);

	int c = a, d = b;
	int min = 0, max = 0;

	int i = 1;
	while (a)
	{
		if (a % 10 == 5)
		{
			max += i;
		}
		else if (a % 10 == 6)
		{
			min -= i;
		}

		i *= 10;
		a /= 10;
	}
	i = 1;
	while (b)
	{
		if (b % 10 == 5)
		{
			max += i;
		}
		else if (b % 10 == 6)
		{
			min -= i;
		}
		i *= 10;
		b /= 10;
	}

	printf("%d %d\n", c+d+min, c+d+max);

	return 0;
}
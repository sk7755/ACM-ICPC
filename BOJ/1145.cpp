#include <cstdio>

int gcd(int a, int b);
int lcd(int a, int b);

int main()
{
	int a[5];

	for (int i = 0; i < 5; i++)
		scanf("%d", &a[i]);

	int min = 1000000000;
	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			for (int k = j + 1; k < 5; k++)
			{
				int l = lcd(lcd(a[i], a[j]), a[k]);

				if (min > l)
					min = l;
			}
		}
	}

	printf("%d\n", min);
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

int lcd(int a, int b)
{
	return a*b / gcd(a, b);
}
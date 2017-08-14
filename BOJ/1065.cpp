#include <cstdio>

int func1(int n);
int func2(int n);

int main()
{
	for (int i = 1; i <= 1000; i++)
	{
		if (func1(i) != func2(i))
			printf("%d -- %d %d\n", i,func1(i), func2(i));
	}

	return 0;

}

int func1(int n)
{
	int a = n / 100, b = n / 10 - 10 * a, c = n % 10;


	if (n < 100)
		return n;
	else
	{
		int num = 99;

		num += (a - 1) * 5;

		if (b >= (a + 1) / 2)
		{
			int temp = b - (a + 1) / 2;
			if (temp > 5)
				temp = 5;
			num += temp;
			if (2 * b - a <= c)
				num++;
		}

		return num;
	}
}

int func2(int n)
{
	int a = n / 100, b = n / 10 - 10 * a, c = n % 10;


	if (n < 100)
		return n;
	else
	{
		int num = 99;

		num += (a - 1) * 5;

		for (int i = (a + 1) / 2; i <= b; i++)
		{
			if (2 * i - a < 10)
			{
				if (i < b)
					num++;
				else if (2 * i - a <= c)
					num++;
			}
		}
		return num;
	}

}
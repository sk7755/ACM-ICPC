#include <cstdio>

int func(int a, int b, int c)
{
	if (a + b == c)
		return 1;
	else if ( a - b  == c)
		return 2;
	else if (a * b == c)
		return 3;
	else if (!(a%b) && a / b == c)
		return 4;
	return 0;
}

int main()
{
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	switch (func(a, b, c))
	{
	case 1:
		printf("%d+%d=%d\n", a, b, c);
		return 0;
	case 2:
		printf("%d-%d=%d\n", a, b, c);
		return 0;
	case 3:
		printf("%d*%d=%d\n", a, b, c);
		return 0;
	case 4:
		printf("%d/%d=%d\n", a, b, c);
		return 0;
	}

	switch (func(b, c, a))
	{
	case 1:
		printf("%d=%d+%d\n", a, b, c);
		return 0;
	case 2:
		printf("%d=%d-%d\n", a, b, c);
		return 0;
	case 3:
		printf("%d=%d*%d\n", a, b, c);
		return 0;
	case 4:
		printf("%d=%d/%d\n", a, b, c);
		return 0;
	}

	return 0;
}
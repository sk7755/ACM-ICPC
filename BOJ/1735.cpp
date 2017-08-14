#include <cstdio>

int main()
{
	int a, b, c, d;

	scanf("%d %d %d %d", &a, &b, &c, &d);

	int A = b*d;
	int B = a*d + b*c;

	a = A, b = B;
	if (b > a)
	{
		int temp = b;
		b = a;
		a = temp;
	}

	while (b)
	{
		a = a%b;
		int temp = b;
		b = a;
		a = temp;
	}

	printf("%d %d\n", B / a, A / a);

	return 0;
}
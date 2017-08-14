#include <cstdio>

int main()
{
	int n;
	int a = 0, b = 1;

	scanf("%d", &n);

	for (int i = 1; i <= n%60; i++)
	{
		int tmp = a + b;
		a = b;
		b = tmp % 10;
	}

	printf("%d\n", b);
}
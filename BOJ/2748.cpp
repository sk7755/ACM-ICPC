#include <cstdio>

int main()
{
	int n;

	scanf("%d", &n);

	long long a = 0, b = 1;
	long long temp;

	for (int i = 2; i <= n; i++)
	{
		temp = a + b;
		a = b;
		b = temp;
	}

	printf("%lld\n", b);

	return 0;
}
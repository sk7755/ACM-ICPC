#include <cstdio>

int main()
{
	long long n;

	scanf("%lld", &n);

	char str[65];
	int top = -1;
	while (n)
	{
		str[++top] = n % 2 +'0';
		n /= 2;
	}

	while (top >= 0)
		printf("%c", str[top--]);
	printf("\n");

	return 0;
}
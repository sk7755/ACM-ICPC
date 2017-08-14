#include <cstdio>

char str[1500000];
int k = 0;

void myitoa(long long n);

int main()
{
	long long a, b;
	scanf("%lld %lld", &a, &b);

	if (a > b)
	{
		long long tmp = a;
		a = b;
		b = tmp;
	}

	if (a == b)
		printf("0\n");
	else
		printf("%lld\n", b - a - 1);
	for (long long i = a+1; i < b; i++)
	{
		myitoa(i);
	}
	str[k++] = '\0';
	printf("%s\n", str);
}

long long stack[20];
int top;

void myitoa(long long n)
{
	top = -1;
	while (n)
	{
		stack[++top] = n % 10 +'0';
		n /= 10;
	}
	while (top >= 0)
		str[k++] = stack[top--];
	str[k++] = ' ';
}
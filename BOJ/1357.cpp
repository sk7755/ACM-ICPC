#include <cstdio>

int rev(int n);

int main()
{
	int x, y;
	scanf("%d %d", &x, &y);

	printf("%d\n", rev(rev(x) + rev(y)));

	return 0;
}

int rev(int n)
{
	int m = 0;
	while (n)
	{
		m *= 10;
		m += n % 10;
		n /= 10;
	}

	return m;
}
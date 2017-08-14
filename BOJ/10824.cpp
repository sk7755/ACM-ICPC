#include <cstdio>

int main()
{
	long long a, b, c, d;

	scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

	int i = 1;
	while (b / i)
		i *= 10;
	int j = 1;
	while (d / j)
		j *= 10;

	printf("%lld\n", a*i + b + c*j + d);

	return 0;
}
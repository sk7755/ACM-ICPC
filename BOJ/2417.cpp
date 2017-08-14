#include <cstdio>

typedef unsigned long long llu;

llu mysqrt(llu n);

int main()
{
	llu n;
	scanf("%llu", &n);

	llu sqrt_n = mysqrt(n);

	llu ans = sqrt_n;
	if (sqrt_n * sqrt_n != n)
		ans++;

	printf("%llu\n", ans);
	return 0;
}

llu mysqrt(llu n)
{
	if (n == 0)
		return 0;

	llu b = n;
	llu a;
	do
	{
		a = b;
		b = (a + n / a) / 2;
	} while (a > b);

	return a;
}
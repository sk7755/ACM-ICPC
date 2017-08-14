#include <cstdio>

int main()
{
	long long n,m;

	scanf("%lld %lld", &n, &m);

	if (m > n)
		printf("%lld\n", m - n);
	else
		printf("%lld\n", n - m);

	return 0;
}
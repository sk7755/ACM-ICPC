#include <cstdio>

int main()
{
	long long n;
	scanf("%lld", &n);

	long long p = 1;
	long long ans = 0;
	while (n)
	{
		ans += (n % 2)*p;
		p *= 3;
		n /= 2;
	}
	printf("%lld\n", ans);

	return 0;
}
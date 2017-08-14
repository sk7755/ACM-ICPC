#include <cstdio>

int main()
{
	long long n;

	scanf("%lld", &n);

	n = n % 45678;

	long long ans = (n *(n - 1)/2) % 45678;
	ans = (ans * 3 + 4 * n + 1) % 45678;

	printf("%lld\n", ans);
	return 0;
}
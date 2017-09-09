#include <cstdio>

int main()
{
	long long n, k;
	scanf("%lld %lld", &n, &k);

	if (n == 1)
	{
		printf("%lld\n", 8 * k);
		return 0;
	}
	if (n == 5)
	{
		printf("%lld\n", 8 * k + 4);
		return 0;
	}

	long long ans;

	if (k % 2)
		ans = 8 * (k / 2) + 9 - n;
	else
		ans = 8 * (k / 2) + n - 1;

	printf("%lld\n", ans);

	return 0;
}
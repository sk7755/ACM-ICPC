#include <cstdio>

int main()
{
	long long x, k;
	scanf("%lld %lld", &x, &k);

	long long ans = 0;

	long long d = 1;
	while (x)
	{
		if (!(x % 2))
		{
			ans += (k % 2)*d;
			k /= 2;
		}
		d *= 2;
		x /= 2;
	}

	while (k)
	{
		ans += (k % 2)*d;
		k /= 2;
		d *= 2;
	}

	printf("%lld\n", ans);

	return 0;
}
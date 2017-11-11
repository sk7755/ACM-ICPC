#include <cstdio>

inline long long min(long long a, long long b)
{
	return a > b ? b : a;
}

int main()
{
	long long x, y, a, b;
	scanf("%lld %lld %lld %lld", &x, &y, &a, &b);
	long long ans = 0;

	if (2 * a > b)
	{
		long long t = min(x, y);
		ans = t * b;
		x -= t;
		y -= t;
	}
	if (a > b)
	{
		ans += ((x + y) / 2) * 2 * b;
		ans += ((x + y) % 2) * a;
	}
	else
		ans += (x + y)*a;
	printf("%lld\n", ans);

	return 0;
}
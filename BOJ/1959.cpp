#include <cstdio>

inline long long min(long long a, long long b)
{
	return a > b ? b : a;
}

int main()
{
	long long n, m;
	scanf("%lld %lld", &n, &m);

	long long s = (min(n, m) - 1) /2;
	long long ans = 4*s;
	
	long long f_x = 1 + s, f_y = 1 + s;

	n -= 2 * s, m -= 2 * s;
	if (n == 1)
		f_y += m-1;
	else if (m == 1)
		ans++, f_x += n - 1;
	else if (n == 2)
		ans += 2, f_x++;
	else if (m == 2)
		ans += 3, f_x++;
	
	printf("%lld\n", ans );
	printf("%lld %lld\n", f_x, f_y);

}
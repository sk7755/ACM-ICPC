#include <cstdio>

long long gcd_std(long long a, long long b, long long *s, long long *t);

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		long long m, n, x, y;

		scanf("%lld %lld %lld %lld", &m, &n, &x, &y);

		long long s, t;
		long long d = gcd_std(m, n, &s, &t);

		if ((x - y) % d)
		{
			printf("-1\n");
			continue;
		}
		t *= (x - y) / d;

		long long ans = (n*t + y - 1) % (m*n / d);
		if (ans < 0)
			ans += m*n / d;

		printf("%lld\n", ans + 1);
	}
}

long long gcd_std(long long a, long long b, long long *s, long long *t)
{
	long long pre_s = 1, pre_t = 0;
	long long q, r;
	long long temp;
	long long trans_flag = 0;

	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;

	*s = 0; *t = 1;

	if (a < b)
	{
		temp = a;
		a = b;
		b = temp;
		trans_flag = 1;
	}

	if (b == 0)
	{
		if (!trans_flag)
			*s = 1, *t = 0;
		return a;
	}

	while ((a%b))
	{
		q = a / b;
		r = a%b;

		temp = *s;
		*s = pre_s - q * *s;
		pre_s = temp;

		temp = *t;
		*t = pre_t - q * *t;
		pre_t = temp;

		a = b;
		b = r;
	}

	if (trans_flag)
	{
		temp = *s;
		*s = *t;
		*t = temp;
	}

	return b;
}
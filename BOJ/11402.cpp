#include <cstdio>

int gcd_std(int a, int b, int *s, int *t);
int mod_factorial(long long a, int p);

int main()
{
	long long n, k;
	int m;

	scanf("%lld %lld %d", &n, &k, &m);

	long long a = n;
	long long b = 0;
	while (a)
	{
		b += a / m;
		a /= m;
	}
	a = k;
	while (a)
	{
		b -= a / m;
		a /= m;
	}
	a = n - k;
	while (a)
	{
		b -= a / m;
		a /= m;
	}

	if (b)
	{
		printf("0\n");
		return 0;
	}

	int lhs = mod_factorial(n, m);
	int rhs = (mod_factorial(k, m) * mod_factorial(n - k, m))%m;

	
	int s, t,d;
	gcd_std(rhs,m,&s,&t);

	s = s*lhs;
	s %= m;

	if (s < 0)
		s += m;

	printf("%d\n", s);

	return 0;

}

int gcd_std(int a, int b, int *s, int *t)
{
	int pre_s = 1, pre_t = 0;
	int q, r;
	int temp;
	int trans_flag = 0;

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

int mod_factorial(long long a, int p)
{
	int result = 1;
	int bound = a%p;
	long long b = a / p;

	if (a == 0)
	{
		return 1;
	}

	if (b % 2)
		result = p-1;

	for (int i = 1; i <= bound; i++)
	{
		result *= i;
		result %= p;
	}

	result *= mod_factorial(b, p);
	result %= p;

	return result;
}
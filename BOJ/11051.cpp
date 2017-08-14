#include <cstdio>

int gcd_std(int a, int b, int *s, int *t);

int main()
{
	int n, k;
	int m = 10007;

	scanf("%d %d", &n, &k);

	int a = 1, b= 1;
	for (int i = 0; i < k; i++)
	{
		a = (a * (n - i)) % m;
		b = (b*(i + 1)) % m;
	}
	int s, t;

	gcd_std(b, m, &s, &t);
	s %= m;
	if (s < 0)
		s += m;

	printf("%d\n", (s*a) % m);

	
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

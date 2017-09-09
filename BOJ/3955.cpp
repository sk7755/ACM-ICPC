#include <cstdio>

void solve();
long long gcd(long long a, long long b, long long* s, long long* t);

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		solve();
	}
}

void solve()
{
	long long k, c;
	scanf("%lld %lld", &k, &c);

	long long s, t;
	long long d = gcd(k, c,&s,&t);

	if (d != 1)
	{
		printf("IMPOSSIBLE\n");
		return;
	}

	gcd(k, c, &s, &t);
	t %= k;
	if (t <= 0)
		t += k;
	
	if (t*c == 1)
		t+=k;

	printf("%lld\n", t);

	return ;


}

long long gcd(long long a, long long b, long long* s, long long* t)
{
	int up = 0, down = 1;
	long long c[2][2];

	c[0][0] = 1, c[0][1] = 0;
	c[1][0] = 0, c[1][1] = 1;
	long long q;
	while (b)
	{
		q = a / b;
		int tmp = a%b;
		a = b;
		b = tmp;

		c[up][0] = c[up][0] - c[down][0] * q;
		c[up][1] = c[up][1] - c[down][1] * q;
		up ^= 1, down ^= 1;
	}

	*s = c[up][0];
	*t = c[up][1];

	return a;
}
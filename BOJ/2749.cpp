#include <cstdio>

enum { m = 1000000};

void mat_mul( long long a[][2], long long b[][2], long long c[][2])
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			c[i][j] = 0;
			for (int k = 0; k < 2; k++)
				c[i][j] += a[i][k] * b[k][j];
			c[i][j] %= m;
		}
	}
}

int main()
{
	long long f[64][2][2];

	f[0][0][0] = f[0][0][1] = f[0][1][0] = 1;
	f[0][1][1] = 0;

	for (int i = 1; i < 64; i++)
	{
		mat_mul(f[i - 1], f[i - 1], f[i]);
	}

	long long n;
	scanf("%lld", &n);

	long long c[2][2] = { { 1, 0 }, { 0, 1 } };
	long long tmp[2][2];

	long long mask = 1;
	for (int i = 0; i < 64; i++, mask = mask << 1)
	{
		if (mask & n)
		{
			mat_mul(c, f[i], tmp);
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 2; k++)
					c[j][k] = tmp[j][k];
			}
		}
	}

	if (c[0][1] < 0)
		c[0][1] += m;

	printf("%lld\n", c[0][1]);

	return 0;
}
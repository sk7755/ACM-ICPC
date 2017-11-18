#include <cstdio>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n;
		long long x[500];
		scanf("%d", &n);

		for (int i = 0; i < n; i++)
			scanf("%lld", &x[i]);
		
		if (n <= 4)
		{
			printf("YES\n");
			continue;
		}

		long long a, b, c, d;
		x[1] -= x[0], x[2] -= x[0], x[3] -= x[0];

		a = x[1] * 6 + x[2] * -6 + x[3] * 2;
		b = x[1] * -48 + x[2] * 42 + x[3] * -12;
		c = x[1] * 114 + x[2] * -84 + x[3] * 22;
		d = 12 * x[0] - a - b - c;

		int success = 1;
		for (int i = 5; i <= n; i++)
		{
			long long j = i*i;
			if ((a*j*i + b*j + c*i + d)/12 != x[i-1])
			{
				success = 0;
				break;
			}
		}
		if (success)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
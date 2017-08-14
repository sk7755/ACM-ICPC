#include <cstdio>

int main()
{
	long long a, b, m;
	long long pow[32] = {0, };

	scanf("%lld %lld %lld", &a, &b, &m);

	pow[0] = a;
	for (int i = 1; i < 32; i++)
		pow[i] = (pow[i - 1] * pow[i - 1]) % m;
	
	long long ans = 1;
	
	for (int i = 0; b; i++, b= b>>1)
	{
		if (b % 2)
			ans = (ans * pow[i]) % m;
	}

	printf("%lld\n", ans);

	return 0;
}
#include <cstdio>

int main()
{
	long long a, b;

	scanf("%lld %lld", &a, &b);

	if (a > b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	long long ans = a;
	ans += b;
	ans = ans *( b - a + 1);
	ans /= 2;

	printf("%lld\n", ans);

	return 0;
}
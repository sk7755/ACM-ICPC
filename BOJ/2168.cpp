#include <cstdio>

int gcd(int a, int b);

int main()
{
	int x, y;
	scanf("%d %d", &x, &y);

	int d = gcd(x, y);
	int t = x / d;
	int s = y / d;
	int ans = (s+t-1) * d;
	printf("%d\n", ans);

	return 0;
}

int gcd(int a, int b)
{
	while (b)
	{
		int tmp = a%b;
		a = b;
		b = tmp;
	}

	return a;
}
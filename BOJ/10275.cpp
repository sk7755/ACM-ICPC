#include <cstdio>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n;
		long long a, b;
		scanf("%d %lld %lld", &n, &a, &b);

		int cnt = 0;
		while (!(a%2))
			a /= 2, cnt++;
		printf("%d\n", n - cnt);
	}
}
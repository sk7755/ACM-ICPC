#include <cstdio>

inline int min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

int count(int n, int p);

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);

	int ans = min(count(n, 5) - count(m, 5) - count(n - m, 5), count(n, 2) - count(m, 2) - count(n - m, 2));

	printf("%d\n",ans);

	return 0;
}

int count(int n, int p)
{
	int ret = 0;
	while (n)
	{
		ret += n / p;
		n /= p;
	}

	return ret;
}
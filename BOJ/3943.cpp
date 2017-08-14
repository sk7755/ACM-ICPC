#include <cstdio>

int h[100001] = { 0,1, };

inline int max(int a, int b)
{
	return a > b ? a : b;
}

int hail(int n)
{
	if (n <= 100000 && h[n])
		return h[n];

	int ret = 1;
	if (n % 2)
		ret = hail(3 * n + 1);
	else
		ret = max(n, hail(n / 2));

	return ret;
}

int main()
{
	for (int i = 2; i <= 100000; i++)
		h[i] = hail(i);

	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n;
		scanf("%d", &n);

		printf("%d\n", h[n]);
	}

	return 0;
}
#include <cstdio>

int main()
{
	int n, m, k;

	scanf("%d %d %d", &n, &m, &k);

	if (n % 2)
		n--, k--;

	if (n > 2 * m)
	{
		k -= n - 2 * m;
		n = 2 * m;
	}
	else
	{
		k -= m - n / 2;
		m = n / 2;
	}
	int diff = 0;
	if (k > 0)
	{
		diff = k / 3;
		if (k % 3)
			diff++;
	}
	printf("%d\n", m-diff);
}
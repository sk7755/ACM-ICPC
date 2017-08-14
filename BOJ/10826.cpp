#include <cstdio>

enum{size = 500, base = 1000000000};

int main()
{
	int a[2][size] = { 0, };
	int n;

	scanf("%d", &n);

	a[1][size - 1] = 1;

	int pre = 0, cur = 1;

	if (n == 0)
	{
		putchar('0');
		return 0;
	}

	for (int i = 2; i <= n; i++)
	{
		int carry = 0;
		for (int j = size - 1; j >= 0; j--)
		{
			a[pre][j] += a[cur][j] + carry;
			if (a[pre][j] >= base)
				a[pre][j] -= base, carry = 1;
			else
				carry = 0;
		}
		pre ^= 1, cur ^= 1;
	}

	int i = 0;
	while (!a[cur][i])
		i++;
	printf("%d", a[cur][i++]);
	for (; i < size; i++)
		printf("%09d", a[cur][i]);

}
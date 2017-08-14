#include <cstdio>

int T_operation(int n);

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n;
		scanf("%d", &n);
		int cnt = 0;
		while (n != 6174)
		{
			n = T_operation(n);
			cnt++;
		}
		printf("%d\n", cnt);
	}
}

int T_operation(int n)
{
	int	cnt[10] = { 0, };

	int m = 0;
	while (n)
	{
		cnt[n % 10]++;
		n /= 10;
		m++;
	}

	cnt[0] += 4 - m;

	int small = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < cnt[i]; j++)
		{
			small *= 10;
			small += i;
		}
	}
	int big = 0;
	for (int i = 9; i >= 0; i--)
	{
		for (int j = 0; j < cnt[i]; j++)
		{
			big *= 10;
			big += i;
		}
	}

	return big - small;
}
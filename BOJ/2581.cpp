#include <cstdio>

int main()
{
	int num[10000] = { 0, };

	for (int i = 3; i <= 100; i += 2)
	{
		for (int j = i*i; j < 10000; j += i)
			num[j] = 1;
	}
	
	int m, n;
	int sum = 0;
	int min;

	scanf("%d %d", &m, &n);
	if (m > 2)
	{
		while (!(m % 2) || num[m] == 1)
			m++;
		if (m > n)
		{
			printf("-1\n");
			return 0;
		}
		min = m;
	}
	else
	{
		if (n < 2)
		{
			printf("-1\n");
			return 0;
		}
		min = 2;
		sum = 2;
		m = 3;
	}

	for (int i = m; i <= n; i+=2)
	{
		if (!num[i])
			sum += i;
	}
	printf("%d\n", sum);
	printf("%d\n", min);

	return 0;
}
#include <cstdio>

int cnt = 0;
int stop;
int ans[10];

void solve(int limit, int k, int digit)
{
	if (k == digit+1)
	{
		cnt++;
		if (cnt == stop+1)
		{
			for (int i = 0; i < k; i++)
				printf("%d", ans[i]);
		}
		return;
	}
	for (int i = 0; i < limit; i++)
	{
		ans[k] = i;
		solve(i, k + 1, digit);
	}
}

int main()
{
	int c[11] = { 0, };

	for (int i = 1; i <= 10; i++)
	{
		int tmp = 1;
		for (int j = 0; j < i; j++)
			tmp *= 10 - j;
		for (int j = 1; j <= i; j++)
			tmp /= j;
		c[i] = c[i - 1] + tmp;
	}

	int n;
	scanf("%d", &n);

	if (n >= 1023)
	{
		printf("-1\n");
	}

	int digit;
	for (digit = 1; digit <= 10; digit++)
	{
		if (c[digit] > n)
			break;
	}
	digit--;
	stop = n - c[digit];
	cnt = 0;

	solve(10, 0, digit);
	printf("\n");
	
	return 0;
}
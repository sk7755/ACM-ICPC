#include <cstdio>

int main()
{
	int n;
	int a[10001] = { 0,1, };
	int f2[10001] = { 0, };

	for (int i = 2; i <= 10000; i++)
	{
		int tmp = i;

		f2[i] = f2[i - 1];
		while (!(tmp % 2))
		{
			tmp /= 2;
			f2[i]++;
		}

		while (!(tmp % 5))
		{
			tmp /= 5;
			f2[i]--;
		}

		a[i] = a[i - 1] * tmp % 10;
	}

	while(scanf("%d",&n) == 1)
	{
		int ans = a[n];
	
		for (int i = 0; i < f2[n]; i++)
			ans = ans * 2 % 10;

		printf("%5d -> %d\n",n, ans);
	}
}
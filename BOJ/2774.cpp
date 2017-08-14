#include <cstdio>

int main()
{
	int t;

	scanf("%d", &t);

	while (t--)
	{
		int n;
		int a[10] = { 0, };

		scanf("%d", &n);

		while (n)
		{
			a[n % 10]++;
			n /= 10;
		}
		int ans = 0;
		for (int i = 0; i < 10; i++)
		{
			if (a[i])
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
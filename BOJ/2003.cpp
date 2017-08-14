#include <cstdio>

int main()
{
	int n, m;

	int a[10001];

	scanf("%d %d", &n, &m);

	a[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		int temp;
		scanf("%d", &temp);
		a[i] = a[i - 1] + temp;
	}

	int k = 0;
	while (m > a[k+1])
		k++;

	int ans = 0;
	for (int i = k+1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[i] - a[j] == m)
				ans++;
		}
	}

	printf("%d\n", ans);

	return 0;
}
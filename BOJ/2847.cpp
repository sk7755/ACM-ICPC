#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	
	int a[100];

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int pre = a[n - 1];
	int ans = 0;
	for (int i = n - 2; i >= 0; i--)
	{
		if (pre <= a[i])
			ans += a[i] - pre + 1, a[i] = pre - 1;

		pre = a[i];
	}

	printf("%d\n", ans);
}
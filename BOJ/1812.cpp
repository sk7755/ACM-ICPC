#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);

	int a[1000];
	int tmp = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (i % 2)
			tmp += a[i];
		else
			tmp -= a[i];
	}

	tmp /= 2;
	a[0] = 2 * tmp;
	for (int i = 1; i <= n; i++)
	{
		tmp = a[i-1] - tmp;
		printf("%d\n",tmp);
	}
}
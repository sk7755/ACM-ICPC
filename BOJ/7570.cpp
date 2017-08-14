#include <cstdio>

int main()
{
	int a[1000001] = { 0, };

	int n;
	scanf("%d", &n);
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		a[tmp] = a[tmp - 1] + 1;

		if (max < a[tmp])
			max = a[tmp];
	}

	printf("%d\n", n - max);

	return 0;
}

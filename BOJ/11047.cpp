#include <cstdio>

int main()
{
	int n, k;
	int a[10];

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int sum = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		sum += k / a[i];
		k = k%a[i];
	}

	printf("%d\n", sum);
}
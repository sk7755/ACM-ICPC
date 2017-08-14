#include <cstdio>

int main()
{
	int n, k;
	int a[20];

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]),getchar();

	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j < n - i; j++)
			a[j] = a[j + 1] - a[j];
	}

	printf("%d", a[0]);
	for (int i = 1; i < n - k; i++)
		printf(",%d", a[i]);
}
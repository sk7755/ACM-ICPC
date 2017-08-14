#include <cstdio>
int main()
{
	int a[101];
	int n;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		a[i] = i;

	for (int i = 1; i <= n; i++)
	{
		int b;
		scanf("%d", &b);
		int temp = i;

		for (int j = i; j > i - b ; j--)
			a[j] = a[j - 1];
		a[i - b] = temp;
		
	}

	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);

	printf("\n");

	return 0;
}
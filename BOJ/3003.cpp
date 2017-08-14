#include <cstdio>

int main()
{
	int a[6] = { 1, 1, 2, 2, 2, 8 };

	for (int i = 0; i < 6; i++)
	{
		int b;
		scanf("%d", &b);
		a[i] -= b;
	}

	for (int i = 0; i < 6; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
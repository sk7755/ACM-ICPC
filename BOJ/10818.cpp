#include <cstdio>

int main()
{
	int n;

	int min = 1000000, max = -1000000;

	scanf("%d", &n);

	int a;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);

		if (a > max)
			max = a;
		if (a < min)
			min = a;
	}

	printf("%d %d", min, max);

	return 0;
}
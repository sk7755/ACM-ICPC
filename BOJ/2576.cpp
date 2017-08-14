#include <cstdio>

int main()
{
	int sum = 0;
	int min = 100;

	for (int i = 0; i < 7; i++)
	{
		int a;
		scanf("%d", &a);

		if (a & 1)
		{
			sum += a;
			if (min > a)
				min = a;
		}
	}

	if (min == 100)
		printf("-1\n");
	else
		printf("%d\n%d\n", sum, min);

	return 0;
}
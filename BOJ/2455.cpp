#include <cstdio>

int main()
{
	int sum = 0, max = 0;
	for (int i = 0; i < 4; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		sum += b - a;

		if (max < sum)
			max = sum;
	}

	printf("%d\n", max);
}
#include <cstdio>

int main()
{
	int a, b;
	int passenger = 0;
	int max = 0;

	for (int i = 0; i < 10; i++)
	{
		scanf("%d %d", &a, &b);
		passenger += b - a;

		if (max < passenger)
			max = passenger;
	}
	printf("%d\n", max);

	return 0;
}
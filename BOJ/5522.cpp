#include <cstdio>

int main()
{
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		int a;
		scanf("%d", &a);
		sum += a;
	}

	printf("%d\n", sum);
	return 0;
}
#include <cstdio>

int main()
{
	int a;
	int sum = 0;

	while (scanf("%d", &a) == 1)
		sum += a;

	printf("%d\n", sum);
}
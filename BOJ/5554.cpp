#include <cstdio>

int main()
{
	int total = 0;
	for (int i = 0; i < 4; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		total += tmp;
	}

	printf("%d\n%d\n", total / 60, total % 60);

	return 0;
}
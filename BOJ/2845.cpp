#include <cstdio>

int main()
{
	int l, p;

	scanf("%d %d", &l, &p);

	for (int i = 0; i < 5; i++)
	{
		int temp;
		scanf("%d", &temp);
		printf("%d ", temp - l*p);
	}
	printf("\n");

	return 0;
}
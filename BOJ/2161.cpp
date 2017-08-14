#include <cstdio>

int main()
{
	int n;

	scanf("%d", &n);

	
	int number[1001] = { 0, };

	for (int i = 1; i <= n; i++)
		number[i] = 1;

	int Throw = 0;
	int start = 1;
	int j = 2;
	while (Throw != n)
	{
		for (int i = start; i <= n; i+=j)
		{
			if (number[i])
			{
				j++;
				if (j % 2)
				{
					Throw++;
					printf("%d ", i);
					number[i] = 0;
				}
			}
		}
	}
	printf("\n");

	return 0;
}
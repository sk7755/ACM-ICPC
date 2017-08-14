#include <cstdio>

int main()
{
	int a[9];
	int sum = 0;

	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
	}
	sum -= 100;

	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (a[i] + a[j] == sum)
			{
				a[i] = a[j] = 0;
				break;
			}
		}
	}

	for (int i = 0; i < 9; i++)
	{
		if (a[i])
			printf("%d\n", a[i]);
	}
	return 0;
}
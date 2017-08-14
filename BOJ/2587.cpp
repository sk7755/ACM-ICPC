#include <cstdio>

int main()
{
	int max1 = 0, max2 = 0, max3 = 0;

	int a;
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &a);
		sum += a;
		if (max1 < a)
		{
			max3 = max2;
			max2 = max1;
			max1 = a;
		}
		else if (max2 < a)
		{
			max3 = max2;
			max2 = a;
		}
		else if (max3 < a)
		{
			max3 = a;
		}
	}

	printf("%d\n%d\n", sum/5,max3);

	return 0;
}
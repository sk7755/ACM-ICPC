#include <cstdio>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int max1 = 0, max2 = 0, max3 = 0;
		for (int i = 0; i < 10; i++)
		{
			int a;
			scanf("%d", &a);

			if (a > max1)
			{
				max3 = max2;
				max2 = max1;
				max1 = a;
			}
			else if (a > max2)
			{
				max3 = max2;
				max2 = a;
			}
			else if (a > max3)
				max3 = a;
		}

		printf("%d\n", max3);
	}

	return 0;
}
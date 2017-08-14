#include <cstdio>

int main()
{
	int max1 = 0, max2 = 0, min = 100;

	for (int i = 0; i < 4; i++)
	{
		int tmp;
		scanf("%d", &tmp);

		if (tmp > max1)
			max2 = max1, max1 = tmp;
		else if (tmp > max2)
			max2 = tmp;

		if (tmp < min)
			min = tmp;
	}

	printf("%d\n",min*max2);

	return 0;
}
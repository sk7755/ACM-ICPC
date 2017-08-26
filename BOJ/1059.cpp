#include <cstdio>

int main()
{
	int interval_n;

	scanf("%d", &interval_n);

	int interval[50];
	
	for (int i = 0; i < interval_n; i++)
		scanf("%d", &interval[i]);

	int k;
	scanf("%d", &k);

	int min = k;
	int max = -1000000000;
	for (int i = 0; i < interval_n; i++)
	{
		int diff = k - interval[i];

		if (diff > 0)
		{
			if (diff < min)
				min = diff;
		}
		else
		{
			if (diff > max)
				max = diff;
		}
	}
	if (min == 0 || max == 0)
		printf("0\n");
	else
		printf("%d\n", min * (-max) - 1);

}
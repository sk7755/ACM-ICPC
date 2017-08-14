#include <cstdio>

int main()
{
	int d[7] = { 0, };

	for (int i = 0; i < 3; i++)
	{
		int a;
		scanf("%d", &a);
		d[a]++;
	}

	int max = 0, dice;
	for (int i = 6; i > 0; i--)
	{
		if (max < d[i])
			max = d[i], dice = i;
	}

	int price;

	if (max == 3)
		price = 10000 + dice * 1000;
	else if (max == 2)
		price = 1000 + dice * 100;
	else
		price = dice * 100;

	printf("%d\n", price);

	return 0;
}
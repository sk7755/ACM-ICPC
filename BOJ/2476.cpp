#include <cstdio>

int main()
{
	int n;

	scanf("%d", &n);

	int max_price = 0;
	for (int i = 0; i < n; i++)
	{
		int a;
		int dice[7] = { 0, };
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &a);
			dice[a]++;
		}
		int max = 0, max_j = 0;
		for (int j = 6; j>0; j--)
		{
			if (max < dice[j])
				max = dice[j], max_j = j;
		}
		int price = 0;

		if (max == 3)
			price = max_j * 1000 + 10000;
		else if (max == 2)
			price = max_j * 100 + 1000;
		else
			price = max_j * 100;

		if (price > max_price)
			max_price = price;
	}

	printf("%d\n", max_price);

	return 0;
}
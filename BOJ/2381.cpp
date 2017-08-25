#include <cstdio>

int main()
{
	int n;
	int max1=-2000000, min1 = 2000000;
	int max2 = -2000000, min2 = 2000000;
	scanf("%d", &n);

	int x, y;
	if (n % 2)
	{
		scanf("%d %d", &x, &y);
		max1 = x + y, min1 = x + y, max2 = y - x, min2 = y - x;
	}
	int m = (n+1)/2;
	int x1, x2, y1, y2;
	for (int i = n%2; i < m; i++)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		if (x1 + y1 > x2 + y2)
		{
			if (max1 < x1 + y1)
				max1 = x1 + y1;
			if (min1 > x2 + y2)
				min1 = x2 + y2;
		}
		else
		{
			if (max1 < x2 + y2)
				max1 = x2 + y2;
			if (min1 > x1 + y1)
				min1 = x1 + y1;
		}
		if (y1 - x1 > y2 - x2)
		{
			if (max2 < y1 - x1)
				max2 = y1 - x1;
			if (min2 > y2 - x2)
				min2 = y2 - x2;
		}
		else
		{
			if (max2 < y2 - x2)
				max2 = y2 - x2;
			if (min2 > y1 - x1)
				min2 = y1 - x1;
		}
	}
	int ans = 0;
	if (max1 - min1 > max2 - min2)
		ans = max1 - min1;
	else
		ans = max2 - min2;
	printf("%d\n", ans);

	return 0;
}
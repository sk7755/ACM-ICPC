#include <cstdio>

int main()
{
	int r, c;
	int x;
	scanf("%d %d %d", &c, &r,&x);

	if (r*c < x)
	{
		printf("0\n");
		return 0;
	}
	int sum = 0;

	int i = 0;
	int limit = x;
	for (;2*r + 2*c - 4 - 8*i >0;i++)
	{
		sum += 2 * r + 2 * c - 4 - 8 * i;
		if (sum >= x)
			break;
		limit = x - sum;
	}

	int ans_x = 1 + i;
	int ans_y = 1 + i;
	for (int j = 1; j < limit; j++)
	{
		if (j < r - 2 * i)
			ans_x++;
		else if (j < r + c - 4 * i - 1)
			ans_y++;
		else if (j < 2 * r + c - 6 * i - 2)
			ans_x--;
		else
			ans_y--;
	}
	printf("%d %d\n", ans_y, ans_x);

	return 0;
}
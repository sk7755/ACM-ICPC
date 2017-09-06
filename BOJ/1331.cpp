#include <cstdio>

inline int abs(int x)
{
	if (x < 0)
		x = -x;

	return x;
}

int main()
{
	char str[3];
	scanf("%s", str);
	int point[6][7] = { 0, };
	int start_x = str[0] - 'A' , start_y = str[1] -'0';
	point[start_x][start_y] = 1;
	int pre_x = start_x, pre_y = start_y;
	int flag = 1;

	 point[start_x][start_y] = 1;
	for (int i = 1; i < 36; i++)
	{
		scanf("%s", str);
		int x = str[0] - 'A', y = str[1] - '0';

		if (x == pre_x || y == pre_y || abs(x - pre_x) + abs(y - pre_y) != 3 || point[x][y])
		{
			flag = 0;
			break;
		}
		point[x][y] = 1;
		pre_x = x, pre_y = y;
	}

	if (start_x == pre_x || start_y == pre_y || abs(start_x - pre_x) + abs(start_y - pre_y) != 3)
		flag = 0;

	if (flag)
		printf("Valid\n");
	else
		printf("Invalid\n");

	return 0;
}
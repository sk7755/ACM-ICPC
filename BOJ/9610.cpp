#include <cstdio>

int main()
{
	int n;
	int q[5] = { 0, }, axis = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);

		if (x == 0 || y == 0)
			axis++;
		else
		{
			if (x>0)
			{
				if (y > 0)
					q[1]++;
				else
					q[4]++;
			}
			else
			{
				if (y > 0)
					q[2]++;
				else
					q[3]++;
			}
		}
	}
	for (int i = 1; i <= 4; i++)
		printf("Q%d: %d\n", i, q[i]);
	printf("AXIS: %d\n", axis);

	return 0;
}
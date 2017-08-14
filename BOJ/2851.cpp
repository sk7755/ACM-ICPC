#include <cstdio>

int main()
{
	int sum = 0;
	int min = 1000;
	int ans = 0;
	for (int i = 0; i < 10; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		sum += tmp;

		int dist = sum - 100;
		if (dist < 0)
			dist = -dist;
		if (min >= dist)
			min = dist ,ans = sum;
	}
	printf("%d\n", ans);

	return 0;
}
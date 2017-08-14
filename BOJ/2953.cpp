#include <cstdio>

int main()
{
	int max = 0;
	int ans;

	for (int i = 1; i <= 5; i++)
	{
		int sum = 0;
		for (int j = 0;j < 4; j++)
		{
			int a;
			scanf("%d", &a);
			sum += a;
		}

		if (max < sum)
			max = sum, ans = i;
	}

	printf("%d %d\n", ans, max);

	return 0;
}
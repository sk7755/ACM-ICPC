#include <cstdio>

int main()
{
	int min = 100;
	int sum = 0;
	for (int i = 0; i < 4; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		sum += tmp;
		if (tmp < min)
			min = tmp;
	}

	sum -= min;
	int a, b;
	scanf("%d %d", &a, &b);
	if (a < b)
		sum += b;
	else
		sum += a;

	printf("%d\n", sum);

	return 0;
}
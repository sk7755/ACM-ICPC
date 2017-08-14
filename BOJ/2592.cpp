#include <cstdio>

int main()
{
	int a[101] = { 0, };

	int b;
	int max = 0, max_value = 0;
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &b);
		sum += b;
		a[b / 10]++;

		if (max < a[b / 10])
			max = a[b / 10], max_value = b;
	}

	printf("%d\n%d\n",sum/10, max_value);
}
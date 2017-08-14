#include <cstdio>

int main()
{
	int n;
	int count[10] = { 0, };

	scanf("%d", &n);

	while (n)
	{
		count[n % 10]++;
		n /= 10;
	}

	int mid = (count[6] + count[9]) / 2;
	count[6] = count[6] + count[9] - mid;
	count[9] = mid;

	int max = 0;
	for (int i = 0; i <= 9; i++)
	{
		if (max < count[i])
			max = count[i];
	}
	printf("%d\n", max);

	return 0;;

}
#include <cstdio>

int main()
{
	int min1= 151, min2 = 151, min3 =151;
	int idx1=0, idx2=0, idx3=0;
	int sum = 0;
	for (int i = 0; i < 8; i++)
	{
		int a;
		scanf("%d", &a);
		sum += a;

		if (min1 > a)
		{
			min3 = min2;
			idx3 = idx2;
			min2 = min1;
			idx2 = idx1;
			min1 = a;
			idx1 = i;
		}
		else if (min2 > a)
		{
			min3 = min2;
			idx3 = idx2;
			min2 = a;
			idx2 = i;
		}
		else if (min3 > a)
		{
			min3 = a;
			idx3 = i;
		}
	}
	printf("%d\n", sum - min1 - min2 - min3);

	int a[8] = { 0, };
	a[idx1] = 1, a[idx2] = 1, a[idx3] = 1;

	for (int i = 0; i < 8; i++)
	{
		if (!a[i])
			printf("%d ", i+1);
	}
	printf("\n");
	return 0;
}
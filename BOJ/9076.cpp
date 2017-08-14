#include <cstdio>

void insertion_sort(int a[], int n);

int main()
{
	int t;
	int a[5];

	scanf("%d", &t);

	while (t--)
	{
		for (int i = 0; i < 5; i++)
			scanf("%d", &a[i]);
		insertion_sort(a, 5);

		if (a[3] - a[1] >= 4)
			printf("KIN\n");
		else
			printf("%d\n", a[1] + a[2] + a[3]);
	}

	return 0;
}

void insertion_sort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int temp = a[i];
		int j;
		for (j = i; j >= 1; j--)
		{
			if (a[j - 1] > temp)
				a[j] = a[j - 1];
			else
			{
				a[j] = temp;
				break;
			}
		}
		if (j == 0)
			a[j] = temp;
	}
}
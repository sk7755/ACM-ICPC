#include <cstdio>

int lower_bound(int a[],int left, int right, int tar)
{
	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (a[mid] > tar)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return left;
}

int main()
{
	int a[40000];
	int n;

	scanf("%d", &n);
	int lis = 1;
	scanf("%d", &a[0]);
	for (int i = 1; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);

		if (a[lis - 1] < tmp)
			a[lis++] = tmp;
		else
			a[lower_bound(a, 0, lis - 1, tmp)] = tmp;
	}

	printf("%d\n", lis);
}
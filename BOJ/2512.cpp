#include <cstdio>

int main()
{
	int n;
	int m;
	scanf("%d", &n);

	int a[10000];

	int left = 0, right = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] > right)
			right = a[i];
	}

	scanf("%d", &m);

	while (left <= right)
	{
		int mid = (left + right) / 2;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] < mid)
				sum += a[i];
			else
				sum += mid;
		}

		if (sum < m)
		{
			left = mid + 1;
		}
		else if (sum > m)
		{
			right = mid - 1;
		}
		else
		{
			right = mid;
			break;
		}
	}

	printf("%d\n", right);
	
}
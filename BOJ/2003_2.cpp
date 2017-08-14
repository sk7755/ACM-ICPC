#include <cstdio>

int main()
{
	int n, m;
	int a[10000];
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	int left = 0, right = 0, sum = a[0];

	int ans = 0;
	do
	{
		if (sum < m)
		{
			sum += a[++right];
		}
		else if (sum > m)
		{
			sum -= a[left++];
			if (left > right)
				right = left;
		}
		else
		{
			sum -= a[left++];
			sum += a[++right];
			ans++;
		}
	}	while (right < n);

	printf("%d\n", ans);

	return 0;
}
#include <cstdio>

int main()
{
	int n, s;
	int a[100000];
	scanf("%d %d", &n, &s);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int left = 0, right = n;

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];

		if (sum >= s)
		{
			right = i;
			break;
		}
	}

	if (right == n)
	{
		printf("0\n");
		return 0;
	}

	int ans = 100000;

	if (ans > right - left + 1)
		ans = right - left + 1;

	for (right = right+1; right < n;right++)
	{
		sum += a[right];
		while (sum >= s)
		{
			sum -= a[left++];
		}
		sum += a[--left];

		if (ans > right - left + 1)
			ans = right - left + 1;
	}
	printf("%d\n", ans);

	return 0;
}
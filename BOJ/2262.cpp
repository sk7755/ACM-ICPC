#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);

	int a[256];

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	int ans = 0;
	//승부하여 패배할 상대를 고른다.
	for (int i = 0; i < n; i++)
	{
		int min = 1000;
		for (int j = i - 1; j >= 0; j--)
		{
			if (a[j] < a[i])
			{
				if(a[i] - a[j] < min)
					min = a[i] - a[j];
				break;
			}
		}
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[i])
			{
				if (a[i] - a[j] < min)
					min = a[i] - a[j];
				break;
			}
		}
		if (min == 1000)
			min = 0;
		ans += min;
	}

	printf("%d\n", ans);

	return 0;
}
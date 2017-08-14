#include <cstdio>

inline void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int n;
	int a[10000];

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int pre = 0;
	int j = -1;
	for (int i = n - 1; i >= 0; i--)
	{
		if (pre > a[i])
		{
			j = i;
			break;
		}
		pre = a[i];
	}
	if (j == -1)
	{
		printf("-1\n");
		return 0;
	}

	int len = n - j - 1;
	for (int i = 0; i < len / 2; i++)
		swap(a[i+j+1], a[len - i +j]);
	for (int i = j + 1; i < n; i++)
	{
		if (a[i] > a[j])
		{
			swap(a[i], a[j]);
			break;
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
}
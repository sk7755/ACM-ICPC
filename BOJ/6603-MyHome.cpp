#include <cstdio>

int a[13];
int n;

int main()
{
	while (true)
	{
		scanf("%d", &n);
		if (n == 0)
			return 0;

		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
	}
}

int combination(int k)
{
	for (int i = k; i < n; i++)
	{
		int tmp = a[i];
		for (int j = i; j>k; j--)
			a[j] = a[j - 1];
		a[k] = tmp;
	}
}
#include <cstdio>

int main()
{
	int n;
	int num[2001] = { 0, };

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int a;

		scanf("%d", &a);
		num[a+1000]++;
	}

	for (int i = 0; i <= 2000; i++)
	{
		if (num[i])
			printf("%d ", i - 1000);
	}
	printf("\n");
	return 0;
}
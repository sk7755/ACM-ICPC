#include <cstdio>

int main()
{
	int a[31] = { 0, };

	for (int i = 0; i < 28; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		a[tmp]++;
	}

	for (int i = 1; i <= 30; i++)
	{
		if (!a[i])
			printf("%d\n", i);
	}

	return 0;
}
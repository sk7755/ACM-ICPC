#include <cstdio>

int main()
{
	int n;

	scanf("%d", &n);

	int a[10] = { 0, };

	while (n)
	{
		a[n % 10]++;
		n /= 10;
	}
	
	for (int i = 9; i >= 0; i--)
	{
		for (int j = 0; j < a[i]; j++)
			printf("%d", i);
	}

	return 0;
}
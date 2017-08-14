#include <cstdio>

int main()
{
	int n;

	scanf("%d", &n);

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		sum += a;
	}

	if (n / 2 < sum)
		printf("Junhee is cute!\n");
	else
		printf("Junhee is not cute!\n");

	return 0;
}
#include <cstdio>

int main()
{
	char str[101];
	int n;

	scanf("%d", &n);
	scanf("%s", str);

	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += str[i] - '0';
	}

	printf("%d\n", sum);

	return 0;
}
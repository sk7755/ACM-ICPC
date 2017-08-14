#include <cstdio>

int main()
{
	int n, b;

	scanf("%d %d", &n, &b);

	char str[33];

	int i;
	for (i = 0; n; i++, n /= b)
	{
		int temp = n%b;

		if (temp < 10)
			str[i] = temp + '0';
		else
			str[i] = temp - 10 + 'A';
	}

	for (i = i - 1; i >= 0; i--)
		printf("%c", str[i]);
	printf("\n");

	return 0;
}
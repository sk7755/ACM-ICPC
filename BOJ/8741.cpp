#include <cstdio>

int main()
{
	int n;
	char buf[2000000];

	scanf("%d", &n);

	int i;

	for (i = 0; i < n; i++)
		buf[i] = '1';
	for (int j = 0; j < n - 1; j++)
		buf[j + i] = '0';
	buf[2 * n - 1] = '\0';

	printf("%s\n", buf);

	return 0;
}
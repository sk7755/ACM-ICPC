#include <cstdio>

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);

	char str[11];
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);

		for (int j = m - 1; j >= 0; j--)
			printf("%c", str[j]);
		printf("\n");
	}
	return 0;
}
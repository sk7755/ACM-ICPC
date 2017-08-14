#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);

	char str[9];
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);
		int a = 0, b = 0;
		for (int i = 0; i < 3; i++)
			a *= 26, a += str[i] - 'A';
		for (int i = 4; i < 8; i++)
			b *= 10, b += str[i] - '0';

		if (-100 <= a - b && a - b <= 100)
			printf("nice\n");
		else
			printf("not nice\n");
	}
	return 0;
}
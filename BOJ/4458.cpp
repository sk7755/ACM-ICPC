#include <cstdio>

int main()
{
	int t;

	scanf("%d", &t);
	getchar();
	while (t--)
	{
		char str[41];

		fgets(str, 40, stdin);

		if (str[0] >= 'a')
			str[0] -= 'a' - 'A';

		printf("%s", str);
	}

	return 0;
}
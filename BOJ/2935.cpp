#include <cstdio>
#include <cstring>

int main()
{
	int a, b;

	char str[101];

	scanf("%s", str);

	int len = strlen(str);
	a = len - 1;

	getchar();
	char op = getchar();

	scanf("%s", str);

	len = strlen(str);
	b = len - 1;

	if (op == '*')
	{
		printf("1");
		for (int i = 0; i < a + b; i++)
			printf("0");
		printf("\n");
	}
	else
	{
		if (a > b)
		{
			int temp = a;
			a = b;
			b = temp;
		}

		if (a < b)
		{
			printf("1");
			for (int i = 0; i < b - a - 1; i++)
				printf("0");
			printf("1");
			for (int i = 0; i < a; i++)
				printf("0");
			printf("\n");
		}
		else
		{
			printf("2");
			for (int i = 0; i < a; i++)
				printf("0");
			printf("\n");
		}
	}

	return 0;
}
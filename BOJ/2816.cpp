#include <cstdio>
#include <cstring>
int main()
{
	int n;
	scanf("%d", &n);

	int a, b;
	for (int i = 1; i <= n; i++)
	{
		char str[11];
		scanf("%s", str);

		if (strcmp(str, "KBS1") == 0)
			a = i;
		if (strcmp(str, "KBS2") == 0)
			b = i;
	}
	int flag = 0;
	if (b < a)
	{
		flag = 1;
		int  tmp = b;
		b = a;
		a = tmp;
	}
	for (int i = 0; i < a - 1; i++)
		printf("1");
	for (int i = 0; i < a - 1; i++)
		printf("4");
	for (int i = 0; i < b - 1; i++)
		printf("1");
	for (int i = 0; i < b - 2; i++)
		printf("4");

	if (flag)
		printf("4");
	printf("\n");

	return 0;
}
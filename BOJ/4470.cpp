#include <cstdio>

int main()
{
	char str[51];

	int n;
	scanf("%d", &n);
	getchar();
	for (int i = 1; i <= n; i++)
	{
		gets(str);
		printf("%d. %s\n",i, str);
	}
}
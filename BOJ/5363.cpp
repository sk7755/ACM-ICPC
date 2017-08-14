#include <cstdio>
#include <cstring>

int main()
{
	char str[101];
	int n;

	scanf("%d", &n);
	getchar();
	while (n--)
	{
		gets(str);

		int len = strlen(str);
		int flag = 0;
		int i;
		for (i = 0; flag != 2; i++)
		{
			if (str[i] == ' ')
				flag++;
		}
		str[i - 1] = '\0';
		printf("%s %s\n", str + i,str);
	}
}
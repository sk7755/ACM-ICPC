#include <cstdio>
#include <cstring>

int main()
{
	char str[101];

	scanf("%s", str);

	int flag = 1;

	for (int i = 0; i < strlen(str); i++)
	{
		if (flag)
		{
			printf("%c", str[i]);
			flag = 0;
		}
		else if (str[i] == '-')
			flag = 1;
	}

	printf("\n");

	return 0;
}
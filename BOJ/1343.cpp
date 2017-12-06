#include <cstdio>
#include <cstring>

int main()
{
	char str[520] = { 0, };

	scanf("%s", str);

	int len = strlen(str);

	for (int i = 0; i < len;)
	{
		if (str[i] == 'X')
		{
			if (str[i + 1] == 'X')
			{
				if (str[i + 2] == 'X' &&str[i + 3] == 'X')
				{
					str[i] = str[i + 1] = str[i + 2] = str[i + 3] = 'A';
					i += 4;
				}
				else
				{
					str[i] = str[i + 1] = 'B';
					i += 2;
				}
			}
			else
			{
				printf("-1\n");
				return 0;
			}
		}
		else
			i++;
	}
	printf("%s\n", str);
}
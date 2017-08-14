#include <cstdio>
#include <cstring>

int main()
{
	char matching[2][4] = { { 'n', 'e', 'm', 'o' }, {'N','E','M','O'} };

	char str[81];
	while (true)
	{
		gets(str);

		if (strcmp(str, "EOI") == 0)
			return 0;

		int len = strlen(str);

		int flag;
		for (int i = 0; i + 3 < len; i++)
		{
			flag = 1;
			for (int j = 0; j < 4; j++)
			{
				if (str[i + j] != matching[0][j] && str[i + j] != matching[1][j])
				{
					flag = 0;
					break;
				}
			}
			if (flag)
			{
				printf("Found\n");
				break;
			}
		}

		if (!flag)
			printf("Missing\n");
	}

	return 0;
}
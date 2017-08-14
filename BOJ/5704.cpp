#include <cstdio>
#include <cstring>

int main()
{
	char str[201];
	while (true)
	{
		gets(str);
		int len = strlen(str);

		int a[26] = { 0, };
		if (str[0] == '*')
			return 0;

		for (int i = 0; i < len; i++)
		{
			if (str[i] != ' ')
				a[str[i] - 'a']++;
		}

		int flag = 1;
		for (int i = 0; i < 26; i++)
		{
			if (!a[i])
			{
				flag = 0;
				break;
			}
		}
		if (flag)
			printf("Y\n");
		else
			printf("N\n");
	}
	return 0;
}
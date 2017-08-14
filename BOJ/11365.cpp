#include <cstdio>
#include <cstring>

int main()
{
	char str[1000];
	while (true)
	{
		gets(str);

		if (strcmp(str, "END") == 0)
			return 0;

		int len = strlen(str);

		for (int i = 0; i < len / 2; i++)
		{
			char tmp = str[i];
			str[i] = str[len - i - 1];
			str[len - i - 1] = tmp;
		}
		printf("%s\n", str);
	}
}
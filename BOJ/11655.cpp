#include <cstdio>
#include <cstring>

int main()
{
	char str[201];

	fgets(str, 200, stdin);

	int len = strlen(str);

	for (int i = 0; i < len; i++)
	{
		if (str[i] >= 'a')
		{
			str[i] = (str[i] - 'a' + 13) % 26 + 'a';
		}
		else if (str[i] >= 'A')
		{
			str[i] = (str[i] - 'A' + 13) % 26 + 'A';
		}
	}
	printf("%s", str);
	return 0;
}
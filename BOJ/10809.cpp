#include <cstdio>
#include <cstring>

int main()
{
	int alphabet[26];

	for (int i = 0; i < 26; i++)
		alphabet[i] = -1;

	char str[101];

	scanf("%s", str);

	int len = strlen(str);

	for (int i = 0; i < len; i++)
	{
		if (alphabet[str[i] - 'a'] == -1)
			alphabet[str[i] - 'a'] = i;
	}

	for (int i = 0; i < 26; i++)
	{
		printf("%d ", alphabet[i]);
	}
	printf("\n");

	return 0;
}
#include <cstdio>
#include <cstring>

int main()
{
	char str[1000010];
	int alphabet[26] = { 0, };

	scanf("%s", str);

	int len = strlen(str);

	for (int i = 0; i < len; i++)
	{
		if (str[i] >= 'a')
			alphabet[str[i] - 'a']++;
		else
			alphabet[str[i] - 'A']++;
	}
	int max = 0;
	int ans;

	for (int i = 0; i < 26; i++)
	{
		if (max < alphabet[i])
			max = alphabet[i], ans = i;
	}

	for (int i = 0; i < 26; i++)
	{
		if (i != ans && max == alphabet[i])
		{
			printf("?\n");
			return 0;
		}
	}

	printf("%c\n", ans + 'A');

	return 0;
}
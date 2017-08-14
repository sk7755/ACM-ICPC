#include <cstdio>
#include <cstring>

int main()
{
	int alphabet[26] = { 0, };
	char str[101];

	scanf("%s", str);

	for (int i = 0; i < strlen(str); i++)
	{
		alphabet[str[i] - 'a']++;
	}
	

	for (int i = 0; i < 26; i++)
		printf("%d ", alphabet[i]);
	printf("\n");

	return 0;
}
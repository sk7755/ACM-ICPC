#include <cstdio>
#include <cstring>

int isPalindrome(char str[], int len);

int main()
{
	char str[1001];

	scanf("%s", str);

	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (isPalindrome(str + i, len - i))
		{
			printf("%d\n", len + i);
			return 0;
		}
	}
}

int isPalindrome(char str[], int len)
{
	for (int i = 0; i < len / 2; i++)
	{
		if (str[i] != str[len - 1 - i])
			return 0;
	}
	return 1;
}
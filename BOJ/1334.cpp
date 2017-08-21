#include <cstdio>
#include <cstring>

int cmp(char a[], char b[], int len);
void make_palin(char src[], char dest[], int len);

int main()
{
	char str[52] = { 0, };

	scanf("%s", str);
	int len = strlen(str);

	char palin[52] = { 0, };

	make_palin(str, palin, len);

	//이경우 한단계 높은 palin을 구현해야한다.
	if (cmp(str, palin, len) >= 0)
	{
		int carry = 1;
		for (int i = (len - 1) / 2; i >= 0; i--)
		{
			str[i] += carry;
			if (str[i] > '9')
			{
				str[i] = '0';
				carry = 1;
			}
			else
				carry = 0;
		}
		if (carry)
		{
			for (int i = len - 1; i >= 0; i--)
				str[i + 1] = str[i];
			str[0] = '1';
			len++;
		}
		make_palin(str, palin, len);
	}
	printf("%s\n", palin);

	return 0;
}

// make palindrome
void make_palin(char src[],char dest[], int len)
{
	for (int i = 0; i < len / 2; i++)
		dest[i] = src[i];
	for (int i = len / 2; i < len; i++)
		dest[i] = src[len - i - 1];
}

int cmp(char a[], char b[], int len)
{
	for (int i = 0; i < len; i++)
	{
		if (a[i] > b[i])
			return 1;
		else if (a[i] < b[i])
			return -1;
	}

	return 0;
}
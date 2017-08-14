#include <cstdio>

int IsPalindrome(int n);

int main()
{
	bool number[1003002] = { 0, };

	for (int i = 2; i <= 1010; i++)
	{
		if (!number[i])
		{
			for (int j = i*i; j <= 1003001; j += i)
				number[j] = true;
		}
	}

	int n;
	scanf("%d", &n);

	for (int i = n;; i++)
	{
		if (!number[i] && IsPalindrome(i))
		{
			printf("%d\n", i);
			return 0;
		}
	}

	return 0;
}

int IsPalindrome(int n)
{
	char str[10];
	int len = 0;

	while (n)
	{
		str[len++] = n % 10;
		n /= 10;
	}

	for (int i = 0; i < len / 2; i++)
	{
		if (str[i] != str[len - i - 1])
			return 0;
	}

	return 1;
}
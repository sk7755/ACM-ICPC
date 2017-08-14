#include <cstdio>
#include <cstring>

void AplusB(char* a, char* b, int len_a, int len_b);

int main()
{
	char a[10010];
	char b[10010];
	
	a[0] = '0';
	b[0] = '0';
	scanf("%s %s", a+1, b+1);

	int len_a = strlen(a);
	int len_b = strlen(b);

	if (len_a > len_b)
	{
		AplusB(a, b, len_a, len_b);
		int flag = 0;
		if (a[0] == '0')
			flag = 1;
		printf("%s\n", a+flag);
	}
	else
	{
		AplusB(b, a, len_b, len_a);
		int flag = 0;
		if (b[0] == '0')
			flag = 1;
		printf("%s\n", b+flag);
	}
}

void AplusB(char* a, char* b, int len_a, int len_b)
{
	int i = len_a - 1;
	int j = len_b - 1;
	int carry = 0;

	while (i >= 0 && j >= 0)
	{
		a[i] += b[j] - '0' +carry;
		if (a[i] > '9')
		{
			a[i] -= 10;
			carry = 1;
		}
		else
			carry = 0;
		i--, j--;
	}

	while (i >= 0)
	{
		a[i] += carry;
		if (a[i] > '9')
		{
			a[i] -= 10;
			carry = 1;
		}
		else
			carry = 0;
		i--;
	}
}
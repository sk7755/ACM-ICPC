#include <cstdio>
#include <cstring>

int main()
{
	char a[81];
	char b[81];
	char c[81];

	for (int i = 0; i < 81; i++)
		a[i] = b[i] = c[i] = '0';

	char str[81];

	scanf("%s", str);
	int len = strlen(str);

	for (int i = len - 1,k=0; i >= 0; i--,k++)
	{
		a[80 - k] = str[i];
	}

	scanf("%s", str);
	len = strlen(str);

	for (int i = len - 1, k = 0; i >= 0; i--, k++)
	{
		b[80 - k] = str[i];
	}

	int carry = 0;
	for (int i = 80; i >= 0; i--)
	{

		c[i] = a[i]+b[i] + carry -'0';
		if (c[i] > '1')
			c[i] -= 2, carry = 1;
		else
			carry = 0;
	}
	int i;
	for (i = 0; i <= 80; i++)
	{
		if (c[i] == '1')
			break;
	}
	if (i == 81)
	{
		printf("0\n");
		return 0;
	}
	for (; i <= 80; i++)
		printf("%c", c[i]);
	return 0;
}
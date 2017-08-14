#include <cstdio>
#include <cstring>

int main()
{
	char str[51];
	int a[26] = { 0, };

	scanf("%s", str);

	int len = strlen(str);

	for (int i = 0; i < len; i++)
		a[str[i] - 'A']++;

	char odd;
	int n_odd = 0;
	for (int i = 0; i < 26; i++)
	{
		if (a[i] % 2)
			odd = i + 'A', n_odd++;
	}

	int stack[100];
	int top = -1;
	if (len % 2)
	{
		if (n_odd != 1)
		{
			printf("I'm Sorry Hansoo\n");
			return 0;
		}
	}
	else
	{
		if (n_odd)
		{
			printf("I'm Sorry Hansoo\n");
			return 0;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < a[i] / 2; j++)
		{
			printf("%c", i + 'A');
			stack[++top] = i;
		}
	}
	if (len%2)
		printf("%c", odd);

	while (top >= 0)
		printf("%c", stack[top--] + 'A');

	return 0;
}
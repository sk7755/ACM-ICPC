#include <cstdio>
#include <cstring>

int main()
{
	char str[1000001];
	char stack[1000001];
	char boom[37];
	int top = -1;

	scanf("%s", str);
	int len_str = strlen(str);
	scanf("%s", boom);
	int len_boom = strlen(boom);

	for (int i = 0; i < len_str; i++)
	{
		stack[++top] = str[i];

		int flag = 1;
		for (int j = top, k = len_boom - 1; j >= 0 && k >= 0; j--, k--)
		{
			if (stack[j] != boom[k])
			{
				flag = 0;
				break;
			}
		}

		if (flag)
			top -= len_boom;
	}

	if (top == -1)
	{
		printf("FRULA\n");
		return 0;
	}

	stack[++top] = '\0';
	printf("%s\n", stack);

	return 0;
}
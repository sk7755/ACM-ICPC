#include <cstdio>
#include <cstring>

int main()
{
	char str[100001];

	scanf("%s", str);

	int top = -1;
	int len = strlen(str);
	int sum = 0;

	for (int i = 0; i < len; i++)
	{
		if (str[i] == '(')
		{
			if (str[i + 1] == ')')
				sum += top + 1, i++;
			else if (str[i + 1] == '(')
				top++;
		}
		else if (str[i] == ')')
		{
			sum++;
			top--;
		}
	}

	printf("%d\n", sum);
	
}
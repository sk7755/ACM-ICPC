#include <cstdio>

int main()
{
	int stack[100001] = { 0, };
	int top = 0;
	char str[400001];
	int t = 0;
	int n;
	int flag = 1;

	scanf("%d", &n);
	int k = 1;

	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);

		if(stack[top] < a)
		{
			while (stack[top] < a)
			{
				str[t++] = '+';
				str[t++] = '\n';
				stack[++top] = k++;
			}
			str[t++] = '-';
			str[t++] = '\n';
			top--;
		}
		else if (stack[top] > a)
		{
			printf("NO\n");
			return 0;
		}
		else
		{
			str[t++] = '-';
			str[t++] = '\n';
			top--;
		}
	}
	str[t++] = '\0';

	printf("%s", str);


	return 0;
}
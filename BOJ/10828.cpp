#include <cstdio>
#include <cstring>

int main()
{
	int t;
	int stack[10000];
	int top = -1;

	scanf("%d", &t);

	char str[10];

	while (t--)
	{
		scanf("%s", str);

		if (strcmp(str, "push") == 0)
		{
			int a;
			scanf("%d", &a);
			stack[++top] = a;
		}
		else if (strcmp(str, "pop") == 0)
		{
			if (top >= 0)
				printf("%d\n", stack[top--]);
			else
				printf("-1\n");
		}
		else if (strcmp(str, "size")==0)
		{
			printf("%d\n", top + 1);
		}
		else if (strcmp(str, "empty")==0)
		{
			if (top >= 0)
				printf("0\n");
			else
				printf("1\n");
		}
		else if (strcmp(str, "top")==0)
		{
			if (top >= 0)
				printf("%d\n", stack[top]);
			else
				printf("-1\n");
		}
	}
}
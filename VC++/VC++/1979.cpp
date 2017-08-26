#include <cstdio>

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	int stack[10000];
	int top = -1;

	int carry = 0;
	int flag = 0;
	stack[++top] = k;

	for (int i = 0; i<100; i++)
	{
		int next = stack[top] * n + carry;
		if (stack[top] && next == k)
		{
			flag = 1;
			break;
		}
		stack[++top] = next % 10;
		carry = next / 10;
	}

	if (flag)
	{
		while (top >= 0)
			printf("%d", stack[top--]);
		printf("\n");
	}
	else
		printf("0\n");

	return 0;
}
#include <cstdio>

int main()
{
	int h[500002];
	int stack[500002];
	int top = -1;
	int n;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &h[i]);
	h[0] = h[n + 1] = 1000000000;
	stack[++top] = 0;

	for (int i = 1; i <= n+1; i++)
	{
		while (h[stack[top]] < h[i])
		{
			int temp = stack[top--];
			h[temp] = stack[top];
		}
		stack[++top] = i;
	}

	for (int i = 1; i <= n; i++)
		printf("%d ", h[i]);
	printf("\n");

	return 0;
}
#include <cstdio>

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);

	int n;
	scanf("%d", &n);

	int dec = 0;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		dec *= a;
		dec += tmp;
	}

	int stack[32];
	int top = -1;

	while (dec)
	{
		stack[++top] = dec % b;
		dec /= b;
	}

	while (top>=0)
		printf("%d ", stack[top--]);
	

	return 0;
}
#include <cstdio>

int main()
{
	int f[45] = { 0, 1, };

	for (int i = 2;i<45; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
	}
	
	int t;
	scanf("%d", &t);

	int stack[50];
	int top;

	while (t--)
	{
		int n;
		scanf("%d", &n);

		top = -1;
		for (int i = 44; i > 0; i--)
		{
			if (f[i] <= n)
			{
				n -= f[i];
				stack[++top] = f[i];
			}
		}
		while (top >= 0)
			printf("%d ", stack[top--]);
		printf("\n");
	}
	return 0;
}
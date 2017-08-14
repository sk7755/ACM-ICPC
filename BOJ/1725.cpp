#include <cstdio>

int main()
{
	int h[100002];
	int stack[100002];
	int top = -1;
	int n;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &h[i]);
	}

	h[0]= 0;
	h[n + 1] = 0;
	stack[++top] = 0;
	int ans = 0;
	for (int i = 1; i <= n+1; i++)
	{
		while (h[stack[top]] > h[i])
		{
			int s = h[stack[top]]* (i - stack[top - 1] -1);
			if (ans < s)
				ans = s;
			top--;
		}
		stack[++top] = i;
	}
	printf("%d\n", ans);

	return 0;
}
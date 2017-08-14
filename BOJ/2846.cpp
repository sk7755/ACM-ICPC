#include <cstdio>

int main()
{
	int n;
	int stack[1000];
	int top = -1;
	scanf("%d", &n);

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int h;
		scanf("%d", &h);

		if (top >= 0)
		{
			if (stack[top] >= h)
			{
				int size = stack[top] - stack[0];

				if (size > ans)
					ans = size;

				top = -1;
			}
		}
		stack[++top] = h;
	}

	if (stack[top] - stack[0] > ans)
		ans = stack[top] - stack[0];

	printf("%d\n", ans);
	return 0;
}
#include <cstdio>

#define MIN(x,y) ((x)>(y) ? (y) :(x))
#define MAX(x,y) ((x)>(y) ? (x) :(y))

int histogram(int m);
int stack[1002];
int h[1002];

int main()
{

	while (true)
	{
		int up = 0, down = 1;
		int n, m;
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0)
			return 0;

		for (int i = 1; i <= m; i++)
			h[i] = 0;
		h[0] = h[m + 1] = -1;

		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				int temp;
				scanf("%d", &temp);
				if (temp)
					h[j] = h[j] + 1;
				else
					h[j] = 0;
					
			}
			int temp = histogram(m);

			if (temp > ans)
				ans = temp;

		}
		printf("%d\n", ans);
	}
}

int histogram(int m)
{
	int top = -1;

	stack[++top] = 0;

	int ret = 0;

	for (int i = 1; i <= m+1; i++)
	{
		while (h[stack[top]] > h[i])
		{
			int temp = stack[top--];

			int s = h[temp] * (i - stack[top] - 1);

			if (ret < s)
				ret = s;
		}
		stack[++top] = i;
	}
	return ret;
}
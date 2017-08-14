#include <cstdio>

int main()
{
	int stack[100002];
	long long h[100002] = { -1,0, };
	while (true)
	{
		int n;
		scanf("%d", &n);
		if (n == 0)
			return 0;
		for (int i = 1; i <= n; i++)
			scanf("%lld", &h[i]);
		h[n + 1] = -1;
		int top = -1;
		stack[++top] = 0;
		long long ans = 0;

		for (int i = 1; i <= n+1; i++)
		{
			while (h[stack[top]] > h[i])
			{
				int temp = stack[top--];

				long long s = h[temp] * (i - stack[top] - 1);
				if (ans < s)
					ans = s;
			}
			stack[++top] = i;
		}

		printf("%lld\n", ans);
	}
}
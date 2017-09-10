#include <cstdio>
#include <cstring>

int main()
{
	char str[500000];
	int len = 0;
	
	for (int i = 1; i <= 100000; i++)
	{
		char stack[6];
		int top = -1;

		int num = i;
		while (num)
		{
			stack[++top] = num % 10 + '0';
			num /= 10;
		}
		while (top >= 0)
			str[len++] = stack[top--];
	}

	char target[7];

	scanf("%s", target);
	int n = strlen(target);

	int ans = 0;
	for (int i = 0; i < len; i++)
	{
		ans++;
		if (i + n <= len)
		{
			int flag = 1;
			for (int j = 0; j < n; j++)
			{
				if (str[i + j] != target[j])
				{
					flag = 0;
					break;
				}
			}

			if (flag)
			{
				printf("%d\n", ans);
				return 0;
			}
		}
	}
	return 0;
}

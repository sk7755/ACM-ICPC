#include <cstdio>
#include <cstring>

int main()
{
	char str[51];
	int top = -1;
	scanf("%s", str);

	int len = strlen(str);
	int ans = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == ')')
		{
			if (top == -1)
				ans++;
			else
				top--;
		}
		else
			top++;
	}
	printf("%d\n", ans+top+1);

	return 0;
}
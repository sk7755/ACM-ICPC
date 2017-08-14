#include <cstdio>
#include <cstring>

int main()
{
	char str[51];
	scanf("%s", str);

	int len = strlen(str);

	int ans = 1;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == 'A')
		{
			if (ans == 1)
				ans = 2;
			else if (ans == 2)
				ans = 1;
		}
		else if (str[i] == 'B')
		{
			if (ans == 2)
				ans = 3;
			else if (ans == 3)
				ans = 2;
		}
		else
		{
			if (ans == 1)
				ans = 3;
			else if (ans == 3)
				ans = 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}
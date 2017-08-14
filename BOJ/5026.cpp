#include <cstdio>
#include <cstring>

int atoi(char* str, int len);

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		char str[100];
		scanf("%s", str);

		if (str[0] == 'P')
		{
			printf("skipped\n");
			continue;
		}

		int len = strlen(str);
		int i;
		int ans = 0;
		for (i = 0; i < len; i++)
		{
			if (str[i] == '+')
			{
				ans += atoi(str, i);
				break;
			}
		}
		ans += atoi(str + i + 1, len - i - 1);

		printf("%d\n", ans);
	}
}

int atoi(char* str, int len)
{
	int ret = 0;
	for (int i = 0; i < len; i++)
	{
		ret *= 10;
		ret += str[i] - '0';
	}

	return ret;
}
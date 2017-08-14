#include <cstdio>
#include <cstring>

int atoi(char str[], int len);

int main()
{
	char str[10001];
	int len = 0;
	while (scanf("%s", str + len) != EOF)
	{
		int tmp= strlen(str + len);
		len += tmp;
	}

	int ans = 0;
	int pre = -1;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == ',')
		{
			ans += atoi(str + pre + 1, i - pre - 1);
			pre = i;
		}
	}
	ans += atoi(str + pre + 1, len - pre - 1);

	printf("%d\n", ans);

	return 0;
}

int atoi(char str[], int len)
{
	int ret = 0;
	for (int i = 0; i < len; i++)
	{
		ret *= 10;
		ret += str[i] - '0';
	}

	return ret;
}
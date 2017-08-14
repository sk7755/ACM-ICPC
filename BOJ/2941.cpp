#include <cstdio>
#include <cstring>

int main()
{
	char str[110] = { 0, };
	scanf("%s", str);
	int len = strlen(str);
	int ans = 0;
	for (int i = 0; i < len;)
	{
		if (str[i] == 'c')
		{
			if (str[i + 1] == '=')
				i += 2;
			else if (str[i + 1] == '-')
				i += 2;
			else
				i++;
		}
		else if (str[i] == 'd')
		{
			if (str[i + 1] == 'z' && str[i + 2] == '=')
				i += 3;
			else if (str[i + 1] == '-')
				i += 2;
			else
				i++;
		}
		else if (str[i] == 'l' && str[i + 1] == 'j')
			i += 2;
		else if (str[i] == 'n' && str[i + 1] == 'j')
			i += 2;
		else if (str[i] == 's' && str[i + 1] == '=')
			i += 2;
		else if (str[i] == 'z' && str[i + 1] == '=')
			i += 2;
		else
			i++;
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}
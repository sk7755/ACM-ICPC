#include <cstdio>
#include <cstring>

int main()
{
	char str[102];
	char ans[102];
	char m[5] = { 'a', 'e', 'i', 'o', 'u' };

	gets(str);

	int len = strlen(str);

	int k = 0;
	for (int i = 0; i <= len;)
	{
		ans[k++] = str[i];
		for (int j = 0; j < 5; j++)
		{
			if (str[i] == m[j])
			{
				i += 2;
				continue;
			}
		}
		i++;
	}

	printf("%s\n", ans);
	return 0;
}
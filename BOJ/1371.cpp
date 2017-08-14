#include <cstdio>
#include <cstring>

int main()
{
	char str[5001];
	int a[26] = { 0, };

	while (gets(str) != NULL)
	{
		int len = strlen(str);

		for (int i = 0; i < len; i++)
		{
			if (str[i] != ' ')
				a[str[i] - 'a']++;
		}
	}
	int max = 0;
	int ans[26];
	int k = 0;
	for (int i = 0; i < 26; i++)
	{
		if (max < a[i])
		{
			max = a[i];
			k = 0;
			ans[k++] = i;
		}
		else if (max == a[i])
			ans[k++] = i;
	}
	for (int i = 0; i < k; i++)
		printf("%c", ans[i] + 'a');
	return 0;
}
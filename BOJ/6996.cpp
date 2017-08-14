#include <cstdio>
#include <cstring>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int a[26] = { 0, };
		int b[26] = { 0, };
		char str1[101], str2[101];

		scanf("%s %s", str1, str2);

		int len1 = strlen(str1);
		int len2 = strlen(str2);
		for (int i = 0; i < len1; i++)
			a[str1[i] - 'a']++;
		for (int i = 0; i < len2; i++)
			b[str2[i] - 'a']++;

		int flag = 1;
		for (int i = 0; i < 26; i++)
		{
			if (a[i] != b[i])
			{
				flag = 0;
				break;
			}
		}

		printf("%s & %s are ", str1, str2);

		if (flag)
			printf("anagrams.\n");
		else
			printf("NOT anagrams.\n");

	}
	return 0;
}
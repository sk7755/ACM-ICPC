#include <cstdio>
#include <cstring>

int main()
{
	char str1[51], str2[52];

	scanf("%s %s", str1, str2);

	int len1 = strlen(str1);
	int len2 = strlen(str2);

	int min = 1000;
	for (int i = 0; i < len2 - len1+1; i++)
	{
		int diff = 0;
		for (int j = 0; j < len1; j++)
		{
			if (str2[i + j] != str1[j])
				diff++;
		}
		if (diff < min)
			min = diff;
	}
	printf("%d\n", min);

	return 0;
}
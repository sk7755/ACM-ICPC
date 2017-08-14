#include <cstdio>
#include <cstring>

int main()
{
	int n;
	char str[100][15];

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%s", str[i]);

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			int len = strlen(str[i]);
			char temp[15];
			for (int k = 0; k < len; k++)
				temp[k] = str[i][len-1- k];
			temp[len] = '\0';

			if (strcmp(temp, str[j]) == 0)
			{
				printf("%d %c\n", len, temp[len / 2]);
				return 0;
			}
		}
	}

	return 0;
}
#include <cstdio>
#include <cstring>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int r;
		char str[21];
		char new_str[161];

		scanf("%d", &r);
		scanf("%s", str);

		int k = 0;
		int len = strlen(str);
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < r; j++)
			{
				new_str[k++] = str[i];
			}
		}
		new_str[k++] = '\0';

		printf("%s\n", new_str);
	}
	return 0;
}
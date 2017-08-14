#include <cstdio>

int main()
{
	char str[5][16] = { 0, };
	char new_str[76];
	int k = 0;

	for (int i = 0; i < 5; i++)
		scanf("%s", str[i]);

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (str[j][i])
				new_str[k++] = str[j][i];
		}
	}
	new_str[k++] = '\0';

	printf("%s\n", new_str);

	return 0;
}
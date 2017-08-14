#include <cstdio>

int main()
{
	char str[100];
	char buffer[11];

	scanf("%s", str);

	int k = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		buffer[k++] = str[i];

		if (k == 10)
		{
			buffer[k++] = '\0';
			printf("%s\n", buffer);
			k = 0;
		}
	}

	buffer[k++] = '\0';
	printf("%s\n", buffer);

	return 0;
}
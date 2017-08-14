#include <cstdio>
#include <cstring>

int main()
{
	char binary[1000001];
	char octal[400000];

	scanf("%s", binary);

	int len = strlen(binary);

	int i;
	int oct = 0;
	for (i = 0; i < len % 3; i++)
	{
		oct = oct << 1;
		oct += binary[i] - '0';
	}

	int k = 0;
	if (oct)
		octal[k++] = oct + '0';

	for (; i < len; i += 3)
	{
		oct = 0;
		for (int j = 0; j < 3; j++)
		{
			oct = oct << 1;
			oct += binary[i + j] - '0';
		}
		octal[k++] = oct +'0';
	}
	octal[k++] = '\0';

	printf("%s\n", octal);

	return 0;
}
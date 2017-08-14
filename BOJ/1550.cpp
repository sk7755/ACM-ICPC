#include <cstdio>
#include <cstring>

int main()
{
	char str[7];

	scanf("%s", str);

	int sum = 0;

	for (int i = 0; i < strlen(str); i++)
	{
		sum *= 16;
		if (str[i] >= 'A')
		{
			sum += str[i] - 'A' + 10;
		}
		else
		{
			sum += str[i] - '0';
		}
	}

	printf("%d\n", sum);

	return 0;
}
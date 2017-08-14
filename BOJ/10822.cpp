#include <cstdio>
#include <cstring>

int main()
{
	char str[101];

	scanf("%s", str);
	int len = strlen(str);

	int sum = 0;
	for (int i = 0; i < len;i++)
	{
		int n = 0;
		while (str[i] != ',' && str[i] != '\0')
		{
			n *= 10;
			n += str[i++] - '0';
		}
		sum += n;
	}
	printf("%d\n", sum);

	return 0;
}
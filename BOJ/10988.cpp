#include <cstdio>
#include <cstring>

int main()
{
	char str[101];

	scanf("%s", str);
	int n = strlen(str);

	for (int i = 0; i < n / 2; i++)
	{
		if (str[i] != str[n - 1 - i])
		{
			printf("0\n");
			return 0;
		}
	}

	printf("1\n");
	return 0;
}
#include <cstring>
#include <cstdio>

int main()
{
	char str[101];

	scanf("%s", str);

	int len = strlen(str);

	int n = 1;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == ',')
			n++;
	}
	printf("%d\n", n);

	return 0;
}
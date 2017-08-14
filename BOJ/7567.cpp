#include <cstdio>
#include <cstring>

int main()
{
	char str[51];

	scanf("%s", str);

	char pre = 0;
	int h = 0;

	for (int i = 0; i < strlen(str); i++)
	{
		if (pre != str[i])
			h += 10;
		else
			h += 5;
		pre = str[i];
	}

	printf("%d\n", h);

	return 0;
}
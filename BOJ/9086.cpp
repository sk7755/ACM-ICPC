#include <cstdio>
#include <cstring>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		char str[1001];

		scanf("%s", str);

		int len = strlen(str);
		printf("%c%c\n", str[0], str[len - 1]);
	}

	return 0;
}
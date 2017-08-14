#include <cstdio>
#include <cstring>

int main()
{
	char str[101];

	scanf("%s", str);
	int len = strlen(str);

	int ans = 0;
	for (int i = 0; i < len % 3; i++)
	{
		ans *= 2;
		ans += str[i] - '0';
	}
	if (len%3)
		printf("%d", ans);
	for (int i = len % 3; i < len; i+=3)
	{
		ans = 0;
		ans += str[i] - '0';
		ans *= 2;
		ans += str[i + 1] - '0';
		ans *= 2;
		ans += str[i + 2] - '0';
		printf("%d", ans);
	}
	printf("\n");

	return 0;
}
#include <cstdio>

int main()
{
	char str[110];

	while (fgets(str, 110, stdin))
		printf("%s", str);

	return 0;
}
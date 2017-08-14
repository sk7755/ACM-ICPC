#include <cstdio>

int main()
{
	char str[201];

	while(fgets(str, 200, stdin))
		printf("%s", str);

	return 0;
}
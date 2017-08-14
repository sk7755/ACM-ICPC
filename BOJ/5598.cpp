#include <cstdio>
#include <cstring>

int main()
{
	char str[1001];
	
	scanf("%s", str);

	int len = strlen(str);

	for (int i = 0; i < len; i++)
	{
		str[i] -= 3;
		if (str[i] < 'A')
			str[i] += 26;
	}

	printf("%s\n", str);

	return 0;
}
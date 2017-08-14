#include <cstdio>
#include <cstring>

int main()
{
	char str[100];

	scanf("%s", str);
	int len = strlen(str);

	for (int i = 1; i < len; i++)
	{
		int a = 1, b= 1;
		for (int j = 0; j < i; j++)
			a *= str[j] - '0';
		
		for (int j = i; j < len; j++)
			b *= str[j] - '0';

		if (a == b)
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");

	return 0;
}
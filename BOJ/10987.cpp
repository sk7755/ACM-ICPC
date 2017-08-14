#include <cstdio>

int main()
{
	char str[101];

	scanf("%s", str);

	int n=0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == 'a')
			n++;
		else if (str[i] == 'e')
			n++;
		else if (str[i] == 'i')
			n++;
		else if (str[i] == 'o')
			n++;
		else if (str[i] == 'u')
			n++;
	}

	printf("%d\n", n);

	return 0;
}
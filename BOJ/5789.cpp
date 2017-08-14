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

		int n = strlen(str);

		if (str[n / 2 - 1] == str[n / 2])
			printf("Do-it\n");
		else
			printf("Do-it-Not\n");
	}

	return 0;
}
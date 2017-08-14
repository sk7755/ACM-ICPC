#include <cstdio>
#include <cstring>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n;
		char str[100];

		scanf("%d", &n);
		scanf("%s", str);

		int len = strlen(str);
		for (int i = n ; i <= len; i++)
			str[i - 1] = str[i];

		printf("%s\n", str);
	}

	return 0;
}
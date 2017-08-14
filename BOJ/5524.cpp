#include <cstdio>
#include <cstring>

int main()
{
	int n;

	scanf("%d", &n);

	char str[21];
	while (n--)
	{
		scanf("%s", str);
		int len = strlen(str);

		for (int i = 0; i < len; i++)
		{
			if (str[i] < 'a')
				str[i] += 'a' - 'A';
		}
		printf("%s\n", str);
	}
	return 0;
}
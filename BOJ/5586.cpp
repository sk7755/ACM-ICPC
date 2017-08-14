#include <cstdio>
#include <cstring>
int main()
{
	char str[10001];

	scanf("%s", str);

	int len = strlen(str);
	int a = 0, b = 0;
	for (int i = 1; i < len - 1; i++)
	{
		if (str[i] == 'O')
		{
			if (str[i + 1] == 'I')
			{
				if (str[i - 1] == 'J')
					a++;
				else if (str[i - 1] == 'I')
					b++;
			}

		}
	}

	printf("%d\n%d\n", a, b);

	return 0;
}
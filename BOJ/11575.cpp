#include <cstdio>
#include <cstring>

int main()
{
	int t;
	scanf("%d", &t);

	char str[1000001];
	while (t--)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		scanf("%s", str);
		int len = strlen(str);

		for (int i = 0; i < len; i++)
		{
			str[i] = ((str[i] - 'A') * a + b) % 26 + 'A';
		}

		printf("%s\n", str);
	}
}
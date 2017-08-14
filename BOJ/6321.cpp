#include <cstdio>
#include <cstring>

int main()
{
	int n;
	scanf("%d", &n);

	char str[51];
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str);
		int len = strlen(str);

		for (int i = 0; i < len; i++)
		{
			str[i]++;
			if (str[i] >'Z')
				str[i] = 'A';
		}
		printf("String #%d\n",i);
		printf("%s\n\n", str);
	}

	return 0;
}
#include <cstdio>
#include <cstring>

int main()
{

	while (true)
	{
		int n;
		scanf("%d", &n);
		getchar();
		if (n == 0)
			return 0;

		char str[110];
		int k = 0;
		for (int i = 0; i < n; i++)
		{
			gets(str);
			int len = strlen(str);

			int j;
			for (j = k; j < len; j++)
			{
				if (str[j] == ' ')
				{
					k = j;
					break;
				}
			}
			if (j == len)
				k = len;

		}
		printf("%d\n", k+1);
	}
	return 0;
}
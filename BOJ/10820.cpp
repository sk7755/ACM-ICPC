#include <cstdio>
#include <cstring>

int main()
{
	while (true)
	{
		char str[102];

		if (fgets(str, 102, stdin) == NULL)
			break;

		int len = strlen(str);

		int ans[4] = { 0, };

		for (int i = 0; i < len; i++)
		{
			if (str[i] >= 'a')
				ans[0]++;
			else if (str[i] >= 'A')
				ans[1]++;
			else if (str[i] >= '0')
				ans[2]++;
			else if (str[i] == ' ')
				ans[3]++;
		}
		for (int i = 0; i < 4; i++)
			printf("%d ", ans[i]);
		printf("\n");
	}

	return 0;
}
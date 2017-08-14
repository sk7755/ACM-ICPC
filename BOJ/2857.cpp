#include <cstdio>
#include <cstring>

int main()
{
	int flag = 0;
	for (int i = 0; i < 5; i++)
	{
		char str[11];
		scanf("%s", str);
		int len = strlen(str);

		for (int j = 0; j < len-2; j++)
		{
			if (str[j] == 'F' && str[j + 1] == 'B' && str[j + 2] == 'I')
				printf("%d ", i + 1), flag = 1;
		}
	}
	if (!flag)
		printf("HE GOT AWAY!");
	printf("\n");

	return 0;
}
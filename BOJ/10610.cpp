#include <cstdio>
#include <cstring>

int main()
{
	char str[100001];
	int num[10] = { 0, };

	scanf("%s", str);

	int len = strlen(str);

	int sum = 0;
	int zero = -1;
	for (int i = 0; i < len; i++)
	{
		sum += str[i] - '0';
		num[str[i] - '0']++;
	}

	int k = 0;
	if (!(sum % 3) && num[0])
	{
		for (int i = 9; i >= 0; i--)
		{
			for (int j = 0; j < num[i]; j++)
				str[k++] = '0' + i;
		}

		printf("%s\n", str);
	}
	else
		printf("-1\n");
}
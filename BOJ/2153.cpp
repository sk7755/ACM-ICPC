#include <cstdio>
#include <cstring>

int main()
{
	char str[21];

	scanf("%s", str);

	int sum = 0;
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (str[i] >= 'a')
			sum += str[i] - 'a' + 1;
		else
			sum += str[i] - 'A' + 27;
	}

	int flag = 1;
	for (int i = 2; i < sum; i++)
	{
		if (!(sum %i))
		{
			flag = 0;
			break;
		}
	}

	if (flag)
		printf("It is a prime word.\n");
	else
		printf("It is not a prime word.\n");

	return 0;
}
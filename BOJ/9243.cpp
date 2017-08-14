#include <cstdio>
#include <cstring>

int main()
{
	int n;

	scanf("%d", &n);

	char str1[1001];
	char str2[1001];

	scanf("%s %s", str1, str2);

	int len = strlen(str1);

	int success = 1;
	if (n % 2)
	{
		for (int i = 0; i < len; i++)
		{
			if (str1[i] == str2[i])
			{
				success = 0;
				break;
			}
		}
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			if (str1[i] != str2[i])
			{
				success = 0;
				break;
			}
		}
	}

	if (success)
		printf("Deletion succeeded\n");
	else
		printf("Deletion failed\n");
}
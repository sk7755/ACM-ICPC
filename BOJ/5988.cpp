#include <cstdio>
#include <cstring>

int main()
{
	int n;

	scanf("%d", &n);

	char num[62];
	for (int i = 0; i < n; i++)
	{
		scanf("%s", num);
		int a = num[strlen(num) - 1] - '0';

		if (a & 1)
			printf("odd\n");
		else
			printf("even\n");
	}

	return 0;
}
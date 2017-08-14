#include <cstdio>

int main()
{
	for (int i = 0; i < 3; i++)
	{
		int sum = 0;
		int a;
		for (int j = 0; j < 4; j++)
		{
			scanf("%d", &a);
			sum += a;
		}
		if (sum == 4)
			sum = -1;
		
		printf("%c\n", 'D' - sum);
	}

	return 0;
}
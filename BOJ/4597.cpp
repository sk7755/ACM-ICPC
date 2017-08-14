#include <cstdio>
#include <cstring>

int main()
{
	char bit[33];

	while (true)
	{
		scanf("%s", bit);
		if (bit[0] == '#')
			return 0;

		int len = strlen(bit);
	
		int a = bit[0] - '0';
		for (int i = 1; i < len - 1; i++)
			a ^= bit[i] - '0';

		if (bit[len - 1] == 'e')
			bit[len - 1] = a ^ 0 + '0';
		else
			bit[len - 1] = a ^ 1 + '0';

		printf("%s\n", bit);
	}
}
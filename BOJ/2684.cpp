#include <cstdio>

int main()
{
	int t;
	scanf("%d", &t);

	char str[41];
	while (t--)
	{
		int h[8] = { 0, };
		scanf("%s", str);

		int pre = 0;
		if (str[0] == 'H')
			pre += 2;
		if (str[1] == 'H')
			pre += 1;
		for (int i = 2; i < 40;i++)
		{
			pre *= 2;
			if (pre >= 8)
				pre -= 8;
			if (str[i] == 'H')
				pre++;

			h[pre]++;
		}

		for (int i = 0; i < 8; i++)
			printf("%d ", h[i]);
		printf("\n");
	}

	return 0;
}
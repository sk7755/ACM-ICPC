#include <cstdio>

inline int abs(int x)
{
	if (x < 0)
		x = -x;

	return x;
}

int main()
{
	char str[5];
	int ans = 0;

	for (int i = 0; i < 4; i++)
	{
		scanf("%s", str);

		for (int j = 0; j < 4; j++)
		{
			if (str[j] != '.')
			{
				int x = (str[j] - 'A') / 4;
				int y = (str[j] - 'A') % 4;

				ans += abs(x - i) + abs(y - j);
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}
#include <cstdio>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int ans = 0;
		while (true)
		{
			int tmp;
			scanf("%d", &tmp);
			char c = getchar();
			ans += tmp;
			if (c == '\n')
				break;
		}
		printf("%d\n", ans);
	}
	return 0;
}
#include <cstdio>

int main()
{
	int t;

	scanf("%d", &t);

	while (t--)
	{
		char ans[21];
		int max = 0;
		int p;
		scanf("%d", &p);

		for (int i = 0; i < p; i++)
		{
			int tmp;
			scanf("%d", &tmp);

			if (tmp > max)
			{
				max = tmp;
				scanf("%s", ans);
			}
			else
				scanf("%*s");
		}

		printf("%s\n", ans);
	}
	return 0;
}
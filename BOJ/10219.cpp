#include <cstdio>
#include <cstring>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		for (int k = 0; k < n; k++)
		{
			char str[12];
			scanf("%s", str);
			char ans[12];
			int len = strlen(str);
			for (int i = len - 1; i >= 0; i--)
			{
				ans[len - i - 1] = str[i];
			}
			ans[len] = 0;
			printf("%s\n", ans);
		}

	}

	return 0;
}
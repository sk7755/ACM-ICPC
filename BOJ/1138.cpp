#include <cstdio>

int main()
{
	int n;
	int ans[10] = { 0, };

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		int tmp;
		scanf("%d", &tmp);

		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (!ans[j])
			{
				if (cnt == tmp)
				{
					ans[j] = i;
					break;
				}
				cnt++;
			}
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i]);
	printf("\n");

	return 0;
}
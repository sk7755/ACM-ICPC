#include <cstdio>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int j = 1;
	int s = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int total = m;
		//필요한건 n개

		while (total)
		{
			int need = n - s;

			if (need == total)
			{
				j++;
				s = 0;
				total = 0;
			}
			else if (need > total)
			{
				s += total;
				total = 0;
			}
			else
			{
				j++;
				s = 0;
				total -= need;
				ans++;
			}
		}
	}
	printf("%d\n", ans);
}
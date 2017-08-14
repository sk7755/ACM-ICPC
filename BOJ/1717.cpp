#include <cstdio>

int main()
{
	int node[1000001];
	int h[1000001] = { 0, };

	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i <= n; i++)
		node[i] = i;

	for (int i = 0; i < m; i++)
	{
		int op, a, b;
		scanf("%d %d %d", &op, &a, &b);

		int j = a;
		while (node[j] != j)
			j = node[j];
		int k = b;
		while (node[k] != k)
			k = node[k];

		if (op == 0)
		{
			if (j != k)
			{
				if (h[j] > h[k])
					node[k] = j;
				else if (h[j] < h[k])
					node[j] = k;
				else
				{
					node[k] = j;
					h[j]++;
				}
			}
		}
		else
		{
			if (j == k)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
}
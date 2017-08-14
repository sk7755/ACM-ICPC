#include <cstdio>

int main()
{
	int tree[50];
	int leaf[50] = { 0, };
	int nvalid[50] = { 0, };
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tree[i]);
		if (tree[i] >= 0)
			leaf[tree[i]]++;
	}

	int del;
	scanf("%d", &del);

	for (int i = 0; i < n; i++)
	{
		int temp = i;
		while (temp != -1)
		{
			if (temp == del)
			{
				leaf[tree[i]]--;
				nvalid[i] = 1;
			}
			temp = tree[temp];
		}
	}
	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		if (!nvalid[i] && !leaf[i])
			ans++;
	}
	printf("%d\n", ans);

	return 0;
}
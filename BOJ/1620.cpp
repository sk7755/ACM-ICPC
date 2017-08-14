#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct poketmon
{
	int idx;
	char* name;
};

int mycmp(poketmon& a, poketmon& b)
{
	if (strcmp(a.name, b.name) < 0)
		return 1;
	else
		return 0;
}

int main()
{
	int n, m;
	char name[100001][21];
	poketmon a[100001];

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
		scanf("%s", name[i]), a[i].idx =i, a[i].name = name[i];

	sort(a+1, a + n + 1, mycmp);

	for (int i = 0; i < m; i++)
	{
		char op[21];
		scanf("%s", op);

		if (op[0] <= '9')
		{
			int len = strlen(op);
			int idx = 0;
			for (int j = 0; j < len; j++)
				idx = idx * 10 + op[j] - '0';
			printf("%s\n", name[idx]);
		}
		else
		{
			int left = 1, right = n;

			while (left <= right)
			{
				int mid = (left + right) / 2;

				int cmp = strcmp(a[mid].name, op);

				if (cmp > 0)
					right = mid - 1;
				else if (cmp < 0)
					left = mid + 1;
				else
				{
					printf("%d\n", a[mid].idx);
					break;
				}
			}

		}
	}

	return 0;
}
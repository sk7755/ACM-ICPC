#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int n;
	scanf("%d", &n);
	int a[26] = { 0, };

	char str[9];
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);
		int len = strlen(str);

		for (int j = len - 1,w=1; j >= 0; j--,w*=10)
		{
			a[str[j] - 'A'] += w;
		}
	}
	sort(a,a+26,cmp);

	int ans = 0;
	int i = 0;
	while (a[i] != 0)
	{
		ans += a[i] * (9 - i);
		i++;
	}

	printf("%d\n", ans);
}
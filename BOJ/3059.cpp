#include <cstdio>
#include <cstring>

int main()
{
	int t;

	scanf("%d", &t);

	char str[1001];
	while (t--)
	{
		int a[26] = { 0, };

		scanf("%s", str);
		int len = strlen(str);
		for (int i = 0; i < len; i++)
			a[str[i] - 'A'] = 1;

		int ans = 0;
		for (int i = 0; i < 26; i++)
		{
			if (!a[i])
				ans += i + 'A';
		}

		printf("%d\n", ans);
	}
	return 0;
}
#include <cstdio>
#include <cstring>

int main()
{
	int n;
	int a[26] = { 0, };
	int b[26];
	int ans = 0;

	scanf("%d", &n);

	char str[11];
	scanf("%s", str);
	int len = strlen(str);

	for (int i = 0; i < len; i++)
		a[str[i] - 'A']++;

	for (int i = 1; i < n; i++)
	{
		scanf("%s", str);
		len = strlen(str);

		for (int j = 0; j < 26; j++)
			b[j] = 0;

		for (int j = 0; j < len; j++)
			b[str[j] - 'A']++;

		int c = 0, d = 0, flag = 1;
		for (int j = 0; j < 26; j++)
		{
			if (a[j] == b[j] + 1)	//a가 하나더 많은것
				c++;
			else if (a[j] + 1 == b[j]) // b가 하나더 많은것
				d++;
			else if (a[j] != b[j]) // 같지도 않은것
				flag = 0;
		}
		if (flag)
		{
			if (c == 0 && d == 0)
				ans++;
			else if (c == 1 || d == 1)
				ans++;
		}

	}
	printf("%d\n", ans);

	return 0;
}
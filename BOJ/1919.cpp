#include <cstdio>
#include <cstring>

int main()
{
	char str1[1001], str2[1001];

	scanf("%s %s", str1, str2);

	int len1 = strlen(str1);
	int len2 = strlen(str2);

	int a[26] = { 0, };
	int b[26] = { 0, };
	for (int i = 0; i < len1; i++)
	{
		a[str1[i] - 'a']++;
	}
	for (int i = 0; i < len2; i++)
	{
		b[str2[i] - 'a']++;
	}

	int ans = 0;
	for (int i = 0; i < 26; i++)
	{
		int dist = a[i] - b[i];
		if (dist < 0)
			dist = -dist;
		ans += dist;
	}

	printf("%d\n", ans);

	return 0;
}
#include <cstdio>
#include <cstring>

int main()
{
	int n;
	int ans = 0;

	scanf("%d", &n);

	while (n--)
	{
		int a[26] = { 0, };
		char str[101];
		scanf("%s", str);
		int len = strlen(str);

		char pre = str[0];
		for (int i = 1; i <= len; i++)
		{
			if (pre != str[i])
			{
				if (a[pre - 'a'])	//error
				{
					ans--;
					break;
				}
				else
					a[pre - 'a'] = 1;
			}
			pre = str[i];
		}
		ans++;


	}
	printf("%d\n", ans);

	return 0;
}
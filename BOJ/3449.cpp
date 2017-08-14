#include <cstdio>
#include <cstring>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		char a[101];
		char b[101];

		scanf("%s", a);
		scanf("%s", b);

		int len = strlen(a);
		int ans = 0;
		for (int i = 0; i < len; i++)
		{
			if (a[i] != b[i])
				ans++;
		}
		printf("Hamming distance is %d.\n", ans);
	}

	return 0;
}
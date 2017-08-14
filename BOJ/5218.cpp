#include <cstdio>
#include <cstring>

int main()
{
	int t;

	scanf("%d", &t);

	while (t--)
	{
		char str1[21], str2[21];

		scanf("%s %s", str1, str2);
		int len = strlen(str1);

		printf("Distances: ");
		for (int i = 0; i < len; i++)
		{
			int ans = str2[i] - str1[i];

			if (ans < 0)
				ans += 26;

			printf("%d ", ans);
		}
		printf("\n");
		
	}
}
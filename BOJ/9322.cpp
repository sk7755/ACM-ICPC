#include <cstdio>
#include <cstring>

int main()
{
	int t;
	scanf("%d", &t);

	char public_key[1000][11];
	int order[1000];

	while (t--)
	{
		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++)
			scanf("%s", public_key[i]);
		
		char str[11];
		for (int i = 0; i < n; i++)
		{
			scanf("%s", str);
			for (int j = 0; j < n; j++)
			{
				if (strcmp(str, public_key[j]) == 0)
				{
					order[i] = j;
					break;
				}
			}
		}
		for (int i = 0; i < n; i++)
			scanf("%s", public_key[order[i]]);
		for (int i = 0; i < n; i++)
			printf("%s ", public_key[i]);
		printf("\n");
	}
}
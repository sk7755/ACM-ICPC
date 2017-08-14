#include <cstdio>
#include <cstring>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n;
		scanf("%d", &n);

		char max_school[21];
		int max = 0;

		for (int i = 0; i < n; i++)
		{
			char temp[21];
			int temp2;
			scanf("%s", temp);
			scanf("%d", &temp2);

			if (temp2 > max)
			{
				max = temp2;
				strcpy(max_school,temp);
			}
		}

		printf("%s\n", max_school);
	}
}
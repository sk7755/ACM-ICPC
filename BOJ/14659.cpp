#include <cstdio>

int main()
{
	int n;

	scanf("%d", &n);

	int pre = 0;
	int count = 0;
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);

		if (tmp > pre)
		{
			if (max < count)
				max = count;
			count = 0;
			pre = tmp;
		}
		else
			count++;
	}

	if (max < count)
		max = count;

	printf("%d\n", max);

	return 0;

}
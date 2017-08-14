#include <cstdio>

int main()
{
	int a[3];

	for (int i = 0; i < 3; i++)
	{
		char buf[9];
		scanf("%s", buf);

		char pre = buf[0];
		int k = 1;
		int ans = 0;
		for (int j = 1; j <= 8; j++)
		{
			if (pre != buf[j])
			{
				if (ans < k)
					ans = k;
				k = 1;
			}
			else
				k++;
			pre = buf[j];
		}
		a[i] = ans;
	}

	for (int i = 0; i < 3; i++)
		printf("%d\n", a[i]);

	return 0;
}
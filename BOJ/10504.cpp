#include <cstdio>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n;
		scanf("%d", &n);

		if (n != 1 && n % 2)
			printf("%d = %d + %d\n", n, (n - 1) / 2, (n + 1) / 2);
		else
		{
			int a = n;
			int b = 1;
			while (!(a % 2))
				a /= 2, b *= 2;
			// a ´Â È¦¼ö, b´Â Â¦¼ö

			if (a == 1)
				printf("IMPOSSIBLE\n");
			else
			{
				int p = 3;
				if ((a % 3))
				{
					p = 5;
					while (p < 2 * b)
					{
						if (a%p)
							break;
						if (a % (p + 2))
							break;
						p += 6;
					}
				}

				printf("%d = ", n);
				if (p < 2 * b)
				{
					int start = n / p - (p - 1) / 2;

					printf("%d ", start);
					for (int i = 1; i < p; i++)
						printf("+ %d ", start + i);
				}
				else
				{
					int start = (a + 1) / 2 - b;

					printf("%d ", start);
					for (int i = 1; i < 2 * b; i++)
						printf("+ %d ", start + i);
				}
				printf("\n");
			}
		}
	}

	return 0;
}
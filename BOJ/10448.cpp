#include <cstdio>

int eureka(int n);
enum {limit = 142};

int T[limit] = { 0, };

int main()
{

	for (int i = 1; i < limit; i++)
		T[i] = T[i - 1] + i;

	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", eureka(n));
	}

	return 0;
}

int eureka(int n)
{
	for (int i = 1; T[i] < n; i++)
	{
		for (int j = i; T[i]+T[j] < n; j++)
		{
			int k;
			for (k = j; T[i] + T[j] + T[k] < n; k++)
				;
			if (T[i] + T[j] + T[k] == n)
				return 1;
		}
	}

	return 0;
}
#include <cstdio>

int main()
{
	int r[42] = { 0, };

	for (int i = 0; i < 10; i++)
	{
		int a;
		scanf("%d", &a);

		r[a % 42]++;
	}

	int ans = 0;

	for (int i = 0; i < 42; i++)
	{
		if (r[i])
			ans++;
	}

	printf("%d\n", ans);

	return 0;
}
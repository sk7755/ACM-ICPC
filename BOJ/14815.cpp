#include <cstdio>

inline int min(int a, int b)
{
	return a > b ? b : a;
}
inline int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int T;

	scanf("%d", &T);

	for(int t = 1; t <= T; t++)
	{
		int n, p;
		int a[3] = { 0, };
		scanf("%d %d", &n, &p);

		int tmp;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &tmp);
			a[tmp%p]++;
		}

		int g = a[0];

		if (p == 2)
		{
			g += a[1] / 2;
			if (a[1] % 2)
				g++;
		}
		else
		{
			tmp = min(a[1], a[2]);
			g += tmp;
			g += (max(a[1], a[2]) - tmp) / 3;
			if ((max(a[1],a[2]) - tmp) % 3)
				g++;
		}
		printf("Case #%d: %d\n", t,g);
	}
	return 0;
}
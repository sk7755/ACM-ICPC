#include <cstdio>
#include <algorithm>

using namespace std;

struct element
{
	long long a;
	long long i;
};

int mycmp(element a, element b)
{
	return a.a * b.i < b.a * a.i;
}

int main()
{
	int n;
	scanf("%d", &n);

	element e[100001] = { 0, };

	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &e[i].a);
		e[i].i = i;
	}

	if (n == 1)
	{
		printf("0\n");
		return 0;
	}

	sort(e + 1, e + n, mycmp);

	element sum[100001] = { 0, };

	for (int i = 1; i < n; i++)
	{
		sum[i].a = sum[i - 1].a + e[i].a;
		sum[i].i = sum[i - 1].i + e[i].i;
	}

	long long x;
	long long ans = 1000000000000000;
	for (int i = 0; i < n; i++)
	{
		if (i == 0 || i == n - 1 || (e[i].a / e[i].i < e[i + 1].a / e[i + 1].i))
		{
			if (sum[i].i < sum[n-1].i - sum[i].i)
				x = e[i + 1].a / e[i + 1].i;
			else
			{
				x = e[i].a / e[i].i;
				if (e[i].a % e[i].i)
					x++;
			}
			long long tmp = (sum[i].i - sum[n - 1].i + sum[i].i) * x + (sum[n - 1].a - 2 * sum[i].a);

			if (tmp < ans)
				ans = tmp;
		}
	}
	printf("%lld\n", ans);

	return 0;
}
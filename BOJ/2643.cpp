#include <cstdio>
#include <algorithm>

using namespace std;

struct paper
{
	int r, c;	//항상 r이 크게 둔다.
};

int mycmp(paper& a, paper& b)
{
	if (a.r == b.r)
		return a.c > b.c;

	return a.r > b.r;
}

int main()
{
	int n;
	scanf("%d", &n);
	
	paper p[100];

	for (int i = 0; i < n; i++)
	{
		int r, c;
		scanf("%d %d", &r, &c);

		if (c>r)
		{
			int tmp = r;
			r = c;
			c = tmp;
		}

		p[i] = { r, c };
	}

	sort(p, p + n, mycmp);

	int dp[100] = { 0, };

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int max = 0;
		for (int j = 0; j < i; j++)
		{
			if (p[i].c <= p[j].c && max < dp[j])
				max = dp[j];
		}
		dp[i] = max + 1;

		if (ans < dp[i])
			ans = dp[i];
	}

	printf("%d\n", ans);
}
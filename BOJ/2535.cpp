
#include <cstdio>
#include <algorithm>

using namespace std;

struct people
{
	int country;
	int number;
	int score;
};

int mycmp(people &a, people &b)
{
	return a.score > b.score;
}

int main()
{
	people p[100];
	int cnt[100] = { 0, };
	int n;
	scanf("%d", &n);


	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &p[i].country, &p[i].number, &p[i].score);
	}

	sort(p, p + n, mycmp);

	int announce = 0;
	for (int i = 0; i < n && announce < 3; i++)
	{
		if (cnt[p[i].country] < 2)
		{
			printf("%d %d\n", p[i].country, p[i].number);
			announce++;
			cnt[p[i].country]++;
		}
	}
}

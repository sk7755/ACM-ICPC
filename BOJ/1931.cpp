#include <cstdio>
#include <algorithm>

using namespace std;

class se
{
public:
	int start, end;

	se(int start = 0, int end = 0) :start(start), end(end) {}
};

int mycmp(se& a, se& b)
{
	if (a.end < b.end)
	{
		return 1;
	}
	else if (a.end > b.end)
	{
		return 0;
	}
	else
	{
		if (a.start < b.start)
			return 1;
		else
			return 0;
	}
}

int main()
{
	int n;
	se a[100000];
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &a[i].start, &a[i].end);
	}
	sort(a, a + n, mycmp);


	int last = 0;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (last <= a[i].start)
		{
			ans++;
			last = a[i].end;
		}
	}

	printf("%d\n", ans);
	
}
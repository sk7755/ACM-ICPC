#include <cstdio>
#include <algorithm>

using namespace std;

class element
{
public:
	int d;
	int idx;

	element(int d = 0, int idx = 0) : d(d), idx(idx){}
};

int mycmp1(element& a, element& b)
{
	return a.d < b.d;
}

int mycmp2(element& a, element& b)
{
	return a.idx < b.idx;
}

int main()
{
	int a[1000000];
	element b[1000000];

	int t;

	scanf("%d", &t);

	while (t--)
	{
		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);

		int m;
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &b[i].d);
			b[i].idx = i;
		}
		sort(b, b + n, mycmp1);

		int i = 0, j = 0;

		while (i < n && j < m)
		{
			if (a[i] < b[j].d)
				i++;
			else if (a[i] > b[j].d)
				b[j++].d = 0;
			else
				b[j++].d = 1;
		}

		while (j < m)
			b[j++].d = 0;
		sort(b, b + n, mycmp2);

		for (int i = 0; i < m; i++)
			printf("%d\n", b[i].d);
	}
	return 0;
}
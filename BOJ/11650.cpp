#include <cstdio>
#include <algorithm>

using namespace std;

struct point
{
	int x, y;
};

int mycmp(point& a, point& b)
{
	if (a.x == b.x)
		return a.y < b.y;
	else
		return a.x < b.x;
}

int main()
{
	int n;
	point p[100000];
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d %d", &p[i].x, &p[i].y);

	sort(p, p + n, mycmp);

	for (int i = 0; i < n; i++)
		printf("%d %d\n", p[i].x, p[i].y);

	return 0;

}
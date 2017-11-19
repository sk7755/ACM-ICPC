#include <cstdio>
#include <algorithm>

using namespace std;
struct point
{
	int x, y;
};

int main()
{
	point p[3];

	for (int i = 0; i < 3; i++)
	{
		scanf("%d %d", &p[i].x, &p[i].y);
	}

	if ((p[0].x - p[1].x) * (p[0].y - p[2].y) == (p[0].x - p[2].x) * (p[0].y - p[1].y))
	{
		printf("X\n");
		return 0;
	}

	int l[3];

	for (int i = 0; i < 3; i++)
	{
		l[i] = (p[i].x - p[(i + 1) % 3].x) * (p[i].x - p[(i + 1) % 3].x) + (p[i].y - p[(i + 1) % 3].y) *(p[i].y - p[(i + 1) % 3].y);
	}

	sort(l, l + 3);

	if (l[0] == l[1] && l[1] == l[2])
	{
		printf("JungTriangle\n");
		return 0;
	}

	if (l[0] == l[1] || l[1] == l[2] || l[2] == l[3])
	{
		if (l[0] + l[1]  ==  l[2])
		{
			printf("Jikkak2Triangle\n");
			return 0;
		}
		else if (l[0] + l[1] < l[2])
		{
			printf("Dunkak2Triangle\n");
			return 0;
		}
		else
		{
			printf("Yeahkak2Triangle\n");
			return 0;
		}
	}

	if (l[0] + l[1] == l[2])
	{
		printf("JikkakTriangle\n");
		return 0;
	}
	else if (l[0] + l[1] < l[2])
	{
		printf("DunkakTriangle\n");
		return 0;
	}
	else
	{
		printf("YeahkakTriangle\n");
		return 0;
	}

}
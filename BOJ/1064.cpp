#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	double p[3][2];

	for (int i = 0; i < 3; i++)
	{
		scanf("%lf %lf", &p[i][0], &p[i][1]);
	}
	
	if (p[0][0] == p[1][0] && p[1][0] == p[2][0])
	{
		printf("-1\n");
		return 0;
	}
	double slope1 = (p[0][1] - p[1][1]) / (p[0][0] - p[1][0]);
	double slope2 = (p[1][1] - p[2][1]) / (p[1][0] - p[2][0]);

	if (slope1 == slope2)
	{
		printf("-1\n");
		return 0;
	}

	double l[3];

	int k = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = i + 1; j < 3; j++)
			l[k++] = (p[i][0] - p[j][0])*(p[i][0] - p[j][0]) + (p[i][1] - p[j][1])*(p[i][1] - p[j][1]);
	}
	sort(l, l + 3);

	double ans = (sqrt(l[2]) - sqrt(l[0])) * 2;
	
	printf("%.10lf\n", ans);

	return 0;
}
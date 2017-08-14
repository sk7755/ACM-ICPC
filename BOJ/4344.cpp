#include <cstdio>

int main()
{
	int t;

	scanf("%d", &t);

	while (t--)
	{
		int n;
		int a[101] = { 0, };

		scanf("%d", &n);

		int avg = 0;
		for (int i = 0; i < n; i++)
		{
			int temp;
			scanf("%d", &temp);
			avg += temp;
			a[temp]++;
		}

		avg /= n;

		int over_avg = 0;
		for (int i = avg+1; i <= 100; i++)
			over_avg += a[i];

		double over_rate = over_avg;
		over_rate = over_rate / n * 100;

		printf("%.3lf%%\n", over_rate);
	}

	return 0;
}
#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);

	int ans = 0;
	int t_d = 0;
	for (int i = 0; i < n;i++)
	{
		int w;
		char g[3];
		scanf("%*s %d %s", &w, g);

		t_d += w;
		int grade = 4 - g[0] + 'A';

		grade *= 10;
		if (g[0] == 'F')
			grade = 0;

		if (g[1] == '+')
			grade += 3;
		else if (g[1] == '-')
			grade -= 3;

		ans += grade * w;
	}
	ans = ans * 100 / t_d;

	if (ans % 10 >= 5)
		ans += 10 - ans % 10;
	else
		ans -= ans % 10;
	int r = ans / 1000;
	ans = ans % 1000;
	int f = ans / 10;
	printf("%d.%02d", r, f);

	return 0;
}
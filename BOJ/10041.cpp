#include <cstdio>

inline int max(int a, int b)
{
	return a > b ? a : b;
}
inline int abs(int a)
{
	return a < 0 ? -a : a;
}
int main()
{
	int w, h, n;
	scanf("%d %d %d", &w, &h, &n);

	int pre_x, pre_y;
	int ans = 0;
	scanf("%d %d", &pre_x, &pre_y);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		int a = pre_x - x;
		int b = pre_y - y;
		if (a*b > 0)
			ans += max(abs(a),abs(b));
		else
			ans += abs(a)+abs(b);

		pre_x = x, pre_y = y;
	}
	printf("%d\n", ans);
}
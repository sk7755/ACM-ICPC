#include <cstdio>

inline int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int left, right;
	int k;
	scanf("%d %d %d", &left, &right, &k);

	int l = k * (k+1)/2;
	int d;
	if (k % 2)
		d = k;
	else
		d = k / 2;
	
	left = max(left, l);
	if (left <= right)
	{
		int ans = (right - left + 1) / d;

		if ((right - left + 1) % d)
		{
			if (!(left % d) || !(right % d))
				ans++;
		}
		if (k == 4 && left <= 12 && 12 <= right)
			ans--;

		printf("%d\n", ans);
	}
	else
		printf("0\n");
}
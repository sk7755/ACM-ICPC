#include <cstdio>

int main()
{
	char cur[9];
	char dest[9];
	int base[3] = { 24, 60, 60 };

	scanf("%s\n%s", cur, dest);

	int ans[3];
	int borrow = 0;
	for (int i = 7, k = 2; i >= 1; i -= 3,k--)
	{
		int c = cur[i] - '0' + (cur[i - 1] - '0') * 10;
		int d = dest[i] - '0' + (dest[i - 1] - '0') * 10;

		ans[k] = d - c - borrow;
		if (ans[k] < 0)
			ans[k] += base[k], borrow = 1;
		else
			borrow = 0;
	}
	if (ans[0] == 0 && ans[1] == 0 && ans[2] == 0)
	{
		printf("24:00:00\n");
		return 0;
	}
	printf("%02d:%02d:%02d\n", ans[0], ans[1], ans[2]);

	return 0;
}
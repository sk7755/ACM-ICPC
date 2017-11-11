#include <cstdio>

typedef unsigned long long llu;

int main()
{
	int n;
	scanf("%d", &n);

	llu a[100001] = { 0, };
	for (int i = 0; i < n; i++)
	{
		scanf("%llu", &a[i+1]);
		a[i + 1] ^= a[i];
	}
	llu ans_bit[64] = { 0, };
	llu mask = 1;
	for (int i = 0; i < 32; i++,mask*=2)
	{
		int up = 1, down = 0;
		int cnt[2] = { 0, };
		for (int j = 1; j <= n; j++)
		{
			if (a[j] & mask)
				cnt[up]++;
			else
				cnt[down]++;
		}
		ans_bit[i] += cnt[up];
		for (int j = 1; j < n; j++)
		{
			if ((a[j] ^ a[j-1]) & mask)
			{
				cnt[up]--;
				up ^= 1, down ^= 1;
			}
			else
				cnt[down]--;

			ans_bit[i] += cnt[up];
		}
	}
	llu ans = 0;
	llu j = 1;
	for (int i = 0;i<64;i++,j*=2)
	{
		ans += j * ans_bit[i];
	}
	printf("%llu\n", ans);

	return 0;
}
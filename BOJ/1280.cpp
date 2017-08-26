#include <cstdio>

enum{m = 1000000007};


long long seg[5000000][2] = { 0, };

void insert_seg(int node, int left, int right, long long key)
{
	if (left <= key && key <= right)
	{
		seg[node][0] += key, seg[node][1]++;
		if (left == right)
			return;
	}
	else
		return;
	int mid = (left + right) / 2;
	insert_seg(node * 2, left, mid,key);
	insert_seg(node * 2 + 1, mid + 1, right, key);
}

long long sum_seg(int node, int left, int right, int start, int end)
{
	if (end < left || right < start)
		return 0;
	else if (start <= left && right <= end)
		return seg[node][0];
	int mid = (left + right) / 2;

	return sum_seg(2 * node, left, mid, start, end) + sum_seg(2 * node + 1, mid + 1, right, start, end);
	
}
long long cnt_seg(int node, int left, int right, int start, int end)
{
	if (end < left || right < start)
		return 0;
	else if (start <= left && right <= end)
		return seg[node][1];
	int mid = (left + right) / 2;

	return cnt_seg(2 * node, left, mid, start, end) + cnt_seg(2 * node + 1, mid + 1, right, start, end);

}

int main()
{
	int n;
	scanf("%d", &n);

	long long x;
	long long ans = 1;
	scanf("%lld", &x);
	insert_seg(1, 0, 200000, x);

	for (int i = 1; i < n; i++)
	{
		scanf("%lld", &x);
		long long tmp = (x * cnt_seg(1, 0, 200000, 0, x - 1) - sum_seg(1, 0, 200000, 0, x - 1)) % m;
		tmp= (tmp + sum_seg(1, 0, 200000, x + 1, 200000) - x * cnt_seg(1, 0, 200000, x+1, 200000))%m;
		ans = (ans*tmp) % m;
		insert_seg(1, 0, 200000, x);
	}

	printf("%lld\n", ans);
}
#include <cstdio>

long long a[1000001];
long long tree[2000001];

long long make_st(int node, int start, int end);
void modify_st(int node, int start, int end);
long long sum_st(int node, int start, int end);
int left, right, target;
long long diff;

int main()
{
	int n,m,k;

	scanf("%d %d %d", &n, &m, &k);

	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);

	make_st(1, 1, n );

	for (int i = 0; i < m + k; i++)
	{
		long long op, b, c;
		scanf("%lld %lld %lld", &op, &b, &c);

		if (op == 1)
		{
			target = b;
			diff = c - a[target];
			modify_st(1, 1, n);
			a[b] = c;
		}
		else
		{
			left = b;
			right = c;
			printf("%lld\n", sum_st(1, 1, n));
		}
	}

	return 0;
}

long long make_st(int node, int start, int end)
{
	if (start == end)
		tree[node] = a[start];
	else
	{
		tree[node] = make_st(node * 2, start, (start + end) / 2);
		tree[node] += make_st(node * 2 + 1, (start + end) / 2 + 1, end);
	}
	return tree[node];
}

void modify_st(int node, int start, int end)
{
	if (start == end)
		tree[node] += diff;
	else
	{
		int mid = (start + end) / 2;

		if (target > mid)
			modify_st(node * 2 + 1, mid + 1, end);
		else
			modify_st(node * 2, start, mid);
		tree[node] += diff;
	}
}

long long sum_st(int node, int start, int end)
{
	if (left > end || right < start)
		return 0;
	else if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;

	return sum_st(node * 2, start, mid) + sum_st(node * 2 + 1, mid + 1,end);
}
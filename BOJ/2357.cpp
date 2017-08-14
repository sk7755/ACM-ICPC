#include <cstdio>

inline int MAX(int a, int b)
{
	if (a < b)
		return b;
	else
		return a;
}

inline int MIN(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

struct mm
{
	int max,min;
};

int a[100001];
mm tree[300001];
void make_st(int node, int start, int end);
mm mm_st(int node, int start, int end, int left, int right);

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	make_st(1, 1, n);

	for (int i = 0; i < m; i++)
	{
		int s, t;
		scanf("%d %d", &s, &t);
		mm ans = mm_st(1, 1, n, s, t);

		printf("%d %d\n", ans.min, ans.max);
	}

	return 0;
}

void make_st(int node, int start, int end)
{
	if (start == end)
		tree[node].max = tree[node].min = a[start];
	else
	{
		int mid = (start + end) / 2;

		make_st(node * 2, start, mid);
		make_st(node * 2 + 1, mid + 1, end);

		tree[node].max = MAX(tree[node * 2].max, tree[node * 2 + 1].max);
		tree[node].min = MIN(tree[node * 2].min, tree[node * 2 + 1].min);
	}
}

mm mm_st(int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
	{
		mm ret;
		ret.max = 0;
		ret.min = 1000000000;
		return ret;
	}

	if (left <= start && end <= right)
		return tree[node];
	else
	{
		int mid = (start + end) / 2;
		mm ret;
		mm l, r;
		l = mm_st(node * 2, start, mid, left, right);
		r = mm_st(node * 2 + 1, mid + 1, end, left, right);

		ret.max = MAX(l.max, r.max);
		ret.min = MIN(l.min, r.min);

		return ret;
	}
}
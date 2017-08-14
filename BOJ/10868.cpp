#include <cstdio>

int n;
int a[100001];
int seg[400000];

int seg_make(int node, int start, int end);
int seg_min(int node, int start, int end, int left, int right);

int main()
{
	int m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	seg_make(1, 1, n);

	for (int i = 0; i < m; i++)
	{
		int b, c;
		scanf("%d %d", &b, &c);

		printf("%d\n",seg_min(1, 1, n, b, c));
	}
}

int seg_make(int node, int start, int end)
{
	if (start == end)
	{
		seg[node] = a[start];
		return a[start];
	}

	int mid = (start + end) / 2;
	int l_node = node * 2;
	int r_node = node * 2 + 1;

	int l_min = seg_make(l_node, start, mid);
	int r_min = seg_make(r_node, mid + 1, end);

	if (l_min < r_min)
		seg[node] = l_min;
	else
		seg[node] = r_min;

	return seg[node];
}

int seg_min(int node, int start, int end, int left, int right)
{
	if (end < left || right < start)
		return 1000000001;

	if (left <= start && end <= right)
		return seg[node];

	int mid = (start+end) / 2;

	int l_min = seg_min(node * 2, start, mid,left,right);
	int r_min = seg_min(node * 2 + 1, mid + 1, end, left, right);

	if (l_min < r_min)
		return l_min;
	else
		return r_min;
}
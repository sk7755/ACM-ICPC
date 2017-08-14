#include <cstdio>

int seg_tree[5000000];
int num[250001] = { 0, };
int start, end;

void make_seg_tree(int node, int left, int right)
{
	if (left == right)
	{
		seg_tree[node] = num[left] ^ 1;
		return;
	}
	int mid = (left + right) / 2;
	make_seg_tree(node * 2, left, mid);
	make_seg_tree(node * 2 + 1, mid + 1, right);
	seg_tree[node] = seg_tree[node * 2] + seg_tree[node * 2 + 1];
}

int num_of_prime(int node, int left, int right)
{
	if (end < left || right < start)
		return 0;

	if (start <= left && right <= end)
		return seg_tree[node];

	int mid = (left + right) / 2;
	int ret = num_of_prime(node * 2, left, mid) + num_of_prime(node * 2 + 1, mid + 1, right);

	return ret;
}

int main()
{

	for (int i = 2; i <= 500; i++)
	{
		if (!num[i])
		{
			for (int j = i*i; j <= 250000; j += i)
				num[j] = 1;
		}
	}
	make_seg_tree(1, 2, 250000);
	while (true)
	{
		int n;
		scanf("%d", &n);

		if (n == 0)
			return 0;
		start = n + 1, end = 2 * n;
		printf("%d\n", num_of_prime(1,2,250000));
	}
}
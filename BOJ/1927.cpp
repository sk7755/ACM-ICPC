#include <cstdio>

int heap[100001] = { 0, };
int n = 0;

void insert_heap(int a);
int delete_heap();

int main()
{
	int t;

	scanf("%d", &t);

	while (t--)
	{
		int a;

		scanf("%d", &a);
		if (a)
			insert_heap(a);
		else
			printf("%d\n",delete_heap());
	}

}

void insert_heap(int a)
{
	int i = ++n;
	while (a < heap[i / 2])
	{
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = a;
}
int delete_heap()
{
	int del = heap[1];

	int temp = heap[n];
	if (n)
	{
		heap[n--] = 0;
		//temp¶û
	}
	int i = 1;
	int next = 1;
	do
	{
		heap[i] = heap[next];
		i = next;

		int left = 2 * i;
		int right = 2 * i + 1;

		next = left;
		if (right <= n && heap[right] < heap[left])
			next = right;

	} while (next <= n && heap[next] < temp);

	if (n)
		heap[i] = temp;

	return del;
}
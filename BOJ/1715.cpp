#include <cstdio>

int heap[100001];
int heap_size = 0;

void push(int key)
{
	int i = ++heap_size;
	while (i > 1 && heap[i / 2] > key)
	{
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = key;
}

int pop()
{
	int ret = heap[1];
	heap[1] = heap[heap_size--];
	int i = 1;
	int smallest;
	while (true)
	{
		if (2 * i <= heap_size && heap[2 * i] < heap[i])
			smallest = 2 * i;
		else
			smallest = i;
		if (2 * i + 1 <= heap_size && heap[2 * i + 1] < heap[smallest])
			smallest = 2 * i + 1;

		if (smallest == i)
			break;

		int tmp = heap[smallest];
		heap[smallest] = heap[i];
		heap[i] = tmp;
		i = smallest;
	}

	return ret;
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		push(tmp);
	}

	int ans = 0;
	while (heap_size != 1)
	{
		int u = pop();
		int v = pop();
		ans += u + v;
		push(u + v);
	}

	printf("%d\n", ans);

	return 0;
}
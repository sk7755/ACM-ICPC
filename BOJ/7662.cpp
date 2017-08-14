#include <cstdio>

typedef struct node* nptr;

struct node
{
	int key;
	int max_idx, min_idx;
};

nptr max_heap[1000001];
nptr min_heap[1000001];
int heap_size = 0;

void push(int key)
{
	int i = ++heap_size;

	nptr pnew = new node;
	pnew->key = key;

	//part of max_heap
	while (i > 1 && max_heap[i / 2]->key < key)
	{
		max_heap[i] = max_heap[i / 2];
		max_heap[i / 2]->max_idx = i;
		i /= 2;
	}
	pnew->max_idx = i;
	max_heap[i] = pnew;


	//part of min_heap
	i = heap_size;

	while (i > 1 && min_heap[i / 2]->key > key)
	{
		min_heap[i] = min_heap[i / 2];
		min_heap[i / 2]->min_idx = i;
		i /= 2;
	}
	pnew->min_idx = i;
	min_heap[i] = pnew;
}

int pop_max()
{
	nptr max = max_heap[1];

	//part of min_heap
	nptr tmp = min_heap[heap_size];
	int i = max->min_idx;
	while (i > 1 && min_heap[i / 2]->key > tmp->key)
	{
		min_heap[i] = min_heap[i / 2];
		min_heap[i / 2]->min_idx = i;
		i /= 2;
	}
	tmp->min_idx = i;
	min_heap[i] = tmp;

	//part of max_heap
	max_heap[1] = max_heap[heap_size--];
	max_heap[1]->max_idx = 1;
	i = 1;
	int largest;

	while (true)
	{
		if (2 * i <= heap_size && max_heap[2 * i]->key > max_heap[i]->key)
			largest = 2 * i;
		else
			largest = i;
		if (2 * i + 1 <= heap_size && max_heap[2 * i + 1]->key > max_heap[largest]->key)
			largest = 2 * i + 1;

		if (largest == i)
			break;

		max_heap[largest]->max_idx = i;
		max_heap[i]->max_idx = largest;

		nptr tmp = max_heap[largest];
		max_heap[largest] = max_heap[i];
		max_heap[i] = tmp;
		i = largest;
	}

	int ret = max->key;
	delete max;

	return ret;
}

int pop_min()
{
	nptr min = min_heap[1];

	//part of max_heap
	nptr tmp = max_heap[heap_size];
	int i = min->max_idx;
	while (i > 1 && max_heap[i / 2]->key < tmp->key)
	{
		max_heap[i] = max_heap[i / 2];
		max_heap[i / 2]->max_idx = i;
		i /= 2;
	}
	max_heap[i] = tmp;
	tmp->max_idx = i;

	//part of min_heap
	min_heap[1] = min_heap[heap_size--];
	min_heap[1]->min_idx = 1;
	i = 1;
	int smallest;

	while (true)
	{
		if (2 * i <= heap_size && min_heap[2 * i]->key < min_heap[i]->key)
			smallest = 2 * i;
		else
			smallest = i;
		if (2 * i + 1 <= heap_size && min_heap[2 * i + 1]->key < min_heap[smallest]->key)
			smallest = 2 * i + 1;

		if (smallest == i)
			break;

		min_heap[smallest]->min_idx = i;
		min_heap[i]->min_idx = smallest;

		nptr tmp = min_heap[smallest];
		min_heap[smallest] = min_heap[i];
		min_heap[i] = tmp;
		i = smallest;
	}

	int ret = min->key;
	delete min;

	return ret;
}


int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n;
		scanf("%d", &n);
		heap_size = 0;
		for (int i = 0; i < n; i++)
		{
			getchar();
			char op = getchar();
			int key;
			scanf("%d", &key);

			if (op == 'I')
				push(key);
			else if (op == 'D' && heap_size > 0)
			{
				if (key == 1)
					pop_max();
				else
					pop_min();
			}

		}

		if (heap_size == 0)
			printf("EMPTY\n");
		else
		{
			int max = pop_max();
			int min = max;

			if (heap_size > 0)
				min = pop_min();

			printf("%d %d\n", max, min);
		}

	}
}
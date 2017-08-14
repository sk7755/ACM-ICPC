#include <cstdio>

template <class T>
class priority_queue
{
private:
	int heap_size;
	T **heap;
	int(*cmp)(T&, T&);
public:
	priority_queue(int size, int(*cmp)(T&, T&)) : heap_size(0), cmp(cmp)
	{
		heap = new T*[size + 1];
	}

	inline void exchange(T*& a, T*& b)
	{
		T* tmp = a;
		a = b;
		b = tmp;
	}

	int size() const
	{
		return heap_size;
	}

	int empty() const
	{
		return heap_size == 0 ? 1 : 0;
	}

	void max_heapify(int idx)
	{
		int largest = idx;
		do
		{
			exchange(heap[idx], heap[largest]);
			idx = largest;
			int left = 2 * idx, right = 2 * idx + 1;

			if (left <= heap_size && cmp(*heap[left], *heap[largest]))
				largest = left;
			if (right <= heap_size && cmp(*heap[right], *heap[largest]))
				largest = right;
		} while (largest != idx);
	}

	T top() const
	{
		if (!empty())
			return *heap[1];
		else
			return NULL;
	}

	void pop()
	{
		if (empty())
			return;

		T* del = heap[1];
		heap[1] = heap[heap_size];
		heap_size--;

		if (!empty())
			max_heapify(1);

		delete del;
	}

	void push(T& key)
	{
		heap[++heap_size] = new T;
		*heap[heap_size] = key;
		int idx = heap_size;

		while (idx > 1 && cmp(*heap[idx], *heap[idx / 2]))
		{
			exchange(heap[idx], heap[idx / 2]);
			idx /= 2;
		}
	}

	~priority_queue()
	{
		delete[] heap;
	}
};

int mycmp(int& a, int& b)
{
	return a < b;
}

int main()
{
	int t;
	scanf("%d", &t);

	priority_queue<int> queue(t, mycmp);

	while (t--)
	{
		int n;
		scanf("%d", &n);

		if (n)
			queue.push(n);
		else
		{
			if (queue.empty())
				printf("0\n");
			else
			{
				printf("%d\n", queue.top());
				queue.pop();
			}
		}
	}

	return 0;
}
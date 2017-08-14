#include <cstdio>

class deck
{
private:
	int data[20001];
	int front, end;
	int size;
public:
	deck()
	{
		size = 0;
		front = 10000;
		end = 9999;
	}

	int get_size()
	{
		return size;
	}

	int empty()
	{
		if (size == 0)
			return 1;
		else
			return 0;
	}
	int get_front()
	{
		if (size)
		{
			return data[front];
		}
		else
		{
			return -1;
		}
	}
	int get_back()
	{

		if (size)
		{
			return data[end];
		}
		else
		{
			return -1;
		}
	}

	void push_front(int a)
	{
		size++;
		data[--front] = a;
	}
	void push_back(int a)
	{
		size++;
		data[++end] = a;
	}
	int pop_front()
	{
		if (size)
		{
			size--;
			return data[front++];
		}
		else
			return -1;
	}
	int pop_back()
	{
		if (size)
		{
			size--;
			return data[end--];
		}
		else
			return -1;
	}
};

int main()
{
	deck d;

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		char op[20];
		scanf("%s", op);
		
		if (op[0] == 'p')	//push,pop
		{
			if (op[1] == 'u')
			{
				int a;
				scanf("%d", &a);
				if (op[5] == 'f')
					d.push_front(a);
				else
					d.push_back(a);
			}
			else
			{
				if (op[4] == 'f')
					printf("%d\n", d.pop_front());
				else
					printf("%d\n", d.pop_back());
			}
		}
		else if (op[0] == 's')
			printf("%d\n", d.get_size());
		else if (op[0] == 'e')
			printf("%d\n", d.empty());
		else if (op[0] == 'f')
			printf("%d\n", d.get_front());
		else
			printf("%d\n", d.get_back());
	}
}
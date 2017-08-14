#include <cstdio>

int queue[10000];
int front = 0, rear = -1;

void push(int a);
int pop();
int size();
int empty();
int Front();
int Back();

int main()
{
	int t;
	char str[10];

	scanf("%d", &t);

	while (t--)
	{
		scanf("%s", str);

		if (str[0] == 'p')
		{
			if (str[1] == 'u')
			{
				int a;
				scanf("%d", &a);
				push(a);
			}
			else
				printf("%d\n", pop());
		}
		else if (str[0] == 's')
			printf("%d\n", size());
		else if (str[0] == 'e')
			printf("%d\n", empty());
		else if (str[0] == 'f')
			printf("%d\n", Front());
		else if (str[0] == 'b')
			printf("%d\n", Back());
	}
}

void push(int a)
{
	queue[++rear] = a;
}

int pop()
{
	if (!empty())
		return queue[front++];
	else
		return -1;
}

int size()
{
	return rear - front + 1;
}
int empty()
{
	if (front > rear)
		return 1;
	else
		return 0;
}

int Front()
{
	if (!empty())
		return queue[front];
	else
		return -1;
}

int Back()
{
	if (!empty())
		return queue[rear];
	else
		return -1;
}

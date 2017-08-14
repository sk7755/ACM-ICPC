#include <cstdio>

struct open
{
	int a, b;
	int move;
};

int main()
{
	int n;
	open start;

	scanf("%d", &n);
	scanf("%d %d", &start.a, &start.b);

	int m;
	scanf("%d", &m);

	open queue[1500000];
	int front = 0, rear = -1;

	queue[++rear] = { start.a, start.b, 0 };
	
	while (m--)
	{
		int target;
		scanf("%d", &target);

		int size = rear - front + 1;

		for (int i = 0; i < size; i++)
		{
			open cur = queue[front++];

			if (target < cur.a)
				queue[++rear] = { target, cur.b, cur.move + cur.a - target };
			else if (cur.a < target && target < cur.b)
			{
				queue[++rear] = { target, cur.b, cur.move + target - cur.a };
				queue[++rear] = { cur.a, target, cur.move + cur.b - target };
			}
			else if (cur.b < target)
				queue[++rear] = { cur.a, target, cur.move + target - cur.b };
			else
				queue[++rear] = { cur.a, cur.b, cur.move };
		}
	}

	int min = 1000000000;
	while (front <= rear)
	{
		open cur = queue[front++];
		if (cur.move < min)
			min = cur.move;
	}
	printf("%d\n", min);

	return 0;
}
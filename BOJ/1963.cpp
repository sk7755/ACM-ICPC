#include <cstdio>

int prime[10001] = { 0, };
int queue[9000];
int visit[10001];

int bfs(int src, int dest);

int main()
{

	for (int i = 2; i < 100; i++)
	{
		if (!prime[i])
		{
			for (int j = i*i;j <= 10000; j += i)
				prime[j] = 1;
		}
	}

	int t;
	scanf("%d", &t);
	
	while (t--)
	{
		int src, dest;
		scanf("%d %d", &src, &dest);
	
		int ret = bfs(src, dest);

		if (ret == -1)
			printf("Impossible\n");
		else
			printf("%d\n", ret);
		
	}
	

	return 0;
}

int bfs(int src, int dest)
{
	for (int i = 0; i < 1000; i++)
		visit[i] = 1;
	for (int i = 1000; i <= 9999; i++)
		visit[i] = 0;

	int front = 0, rear = -1;

	queue[++rear] = src;
	visit[src] = 1;

	int move = -1;
	int temp;
	while (front <= rear)
	{
		move++;
		int size = rear - front + 1;

		for (int k = 0; k < size; k++)
		{
			int cur = queue[front++];
			if (cur == dest)
				return move;

			int digit_num[4];
			temp = cur;
			for (int i = 0; i < 4; i++)
			{
				digit_num[i] = temp % 10;
				temp /= 10;
			}

			for (int i = 0, digit = 1; i < 4; i++, digit *= 10)
			{
				 temp = cur - digit_num[i] * digit;
				for (int j = 0; j < 10; j++)
				{
					int cand = temp + j*digit;
					if (!prime[cand] && !visit[cand])
					{
						queue[++rear] = cand;
						visit[cand] = 1;
					}
				}

			}
		}
	}

	return -1;
}
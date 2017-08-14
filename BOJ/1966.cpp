#include <cstdio>
#include <algorithm>

using namespace std;

struct element
{
	int idx;
	int data;
};

int mycmp(int& a, int& b)
{
	return a > b;
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n, m;
		scanf("%d %d", &n, &m);

		int a[100];
		element queue[10000];
		int front = 0, rear = -1;

		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]), queue[++rear].data = a[i], queue[rear].idx = i;

		sort(a, a + n,mycmp);
		int k = 0;

		while (front <= rear)
		{
			element cur = queue[front++];
			if (cur.data < a[k])
			{
				queue[++rear] = cur;
			}
			else
			{
				if (m == cur.idx)
					break;
				k++; 
			}
		}

		printf("%d\n", k+1);
	}

	return 0;
}
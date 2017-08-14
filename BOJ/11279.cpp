#include <queue>
#include <cstdio>
#include <vector>
#include <functional>

using namespace std;

int main()
{
	int n;
	priority_queue<int, vector<int>, less<int>> q;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int m;

		scanf("%d", &m);

		if (m == 0)
		{
			if (!q.empty())
			{
				printf("%d\n", q.top());
				q.pop();
			}
			else
				printf("0\n");
		}
		else
			q.push(m);

	}

	return 0;
}
#include <cstdio>

struct point
{
	int x, y;
};

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int l, k;
	scanf("%d %d", &l, &k);

	point star[100];
	int ans = 0;

	for (int i = 0; i < k; i++)
		scanf("%d %d", &star[i].x, &star[i].y);

	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			int start_x = star[i].x;
			int start_y = star[j].y;

			int finish_x = start_x + l;
			int finish_y = start_y + l;

			int count = 0;
			for (int s = 0; s < k; s++)
			{
				if (start_x <= star[s].x && star[s].x <= finish_x && start_y <= star[s].y && star[s].y <= finish_y)
					count++;
			}
			if (count > ans)
				ans = count;
		}
	}

	printf("%d\n",k- ans);

	return 0;
}
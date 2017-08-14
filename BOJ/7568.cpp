#include <cstdio>

class person
{
public:
	int w, h;

	person(int w = 0, int h = 0) : w(w), h(h) {}
};

int main()
{
	int n;

	scanf("%d", &n);

	person p[50];

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &p[i].w, &p[i].h);
	}

	for (int i = 0; i < n; i++)
	{
		int t = 0;
		for (int j = 0; j < n; j++)
		{
			if (p[i].w < p[j].w && p[i].h < p[j].h)
				t++;
		}
		printf("%d ", t+1);
	}
	printf("\n");

	return 0;
}
#include <cstdio>


int main()
{
	int f, s, g, u, d;

	scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);

	int nU=0, nD = 0;
	int visit[1000001] = { 0, };

	while (!visit[s])
	{
		visit[s] = 1;
		if (s == g)
		{
			printf("%d\n", nU + nD);
			return 0;
		}
		if (s < g)
		{
			if (s + u <= f)
				s += u, nU++;
			else
				s -= d, nD++;
		}
		else
		{
			if (s - d >= 1)
				s -= d, nD++;
			else
				s += u, nU++;
		}
	}
	printf("use the stairs\n");

	return 0;

}

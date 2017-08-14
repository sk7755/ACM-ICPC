#include <cstdio>

int get_inverse(int a, int m);

int main()
{
	int a1, a2, a3;
	scanf("%d %d %d", &a1, &a2, &a3);

	int M1 = 28*19, M2 =15*19 , M3 = 15*28;
	
	int y1 = get_inverse(M1, 15);
	int y2 = get_inverse(M2, 28);
	int y3 = get_inverse(M3, 19);

	int ans = (a1*M1*y1 + a2*M2*y2 + a3*M3*y3);

	printf("%d\n", (ans - 1) % 7980 + 1);

	return 0;

}

int get_inverse(int a, int m)
{
	for (int i = 1; i < m; i++)
	{
		if ((a*i) % m == 1)
			return i;
	}
}
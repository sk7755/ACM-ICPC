
//https://www.acmicpc.net/problem/2916
//2916번: 자와 각도기
//ax + by = (a,b)k (x,y,k는 integer)
//따라서 더하거나 빼서 만들 수 있는 수는 최대공약수의 배수이다.
//주의 사항은 360도 각도기도 기본적으로 가지고있다고 생각해야한다.
//따라서 d를 360으로 초기화 시켜주고 최대공약수를 구했다.

#include <cstdio>

int gcd(int a, int b);

int main()
{
	int arc_src[10];
	int n, t;

	scanf("%d %d", &n, &t);

	for (int i = 0; i < n; i++)
		scanf("%d", &arc_src[i]);

	int d = 360;
	for (int i = 0; i < n; i++)
	{
		d = gcd(d, arc_src[i]);
	}

	while (t--)
	{
		int arc_dest;
		scanf("%d", &arc_dest);

		if (!(arc_dest % d))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

int gcd(int a, int b)
{
	while (b)
	{
		int tmp = b;
		b = a%b;
		a = tmp;
	}

	return a;
}

//https://www.acmicpc.net/problem/2916
//2916��: �ڿ� ������
//ax + by = (a,b)k (x,y,k�� integer)
//���� ���ϰų� ���� ���� �� �ִ� ���� �ִ������� ����̴�.
//���� ������ 360�� �����⵵ �⺻������ �������ִٰ� �����ؾ��Ѵ�.
//���� d�� 360���� �ʱ�ȭ �����ְ� �ִ������� ���ߴ�.

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
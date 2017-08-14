#include <cstdio>

int main()
{
	int a, b, c;
	int t[100] = { 0, };
	scanf("%d %d %d", &a, &b, &c);

	for (int i = 0; i < 3; i++)
	{
		int start, end;
		scanf("%d %d", &start, &end);

		for (int j = start; j < end; j++)
			t[j]++;
	}
	int price = 0;
	for (int i = 1; i <= 100; i++)
	{
		if (t[i] == 1)
			price += a;
		else if (t[i] == 2)
			price += 2*b;
		else if (t[i] == 3)
			price += 3*c;
	}
	printf("%d\n", price);
}
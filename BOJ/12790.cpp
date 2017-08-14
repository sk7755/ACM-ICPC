#include <cstdio>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int hp, mp, atk, def;

		scanf("%d %d %d %d", &hp, &mp, &atk, &def);

		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);

		hp += a, mp += b, atk += c, def += d;
		if (hp < 1)
			hp = 1;
		if (mp < 1)
			mp = 1;
		if (atk < 0)
			atk = 0;

		printf("%d\n", hp + 5 * mp + 2 * atk + 2 * def);
	}
}
#include <cstdio>

class fraction
{
public:
	int nom;
	int denom;

	fraction(int nom, int denom) : nom(nom), denom(denom)
	{}

	fraction& operator-=(fraction rhs)
	{
		nom = nom*rhs.denom - denom*rhs.nom;
		denom = rhs.denom * denom;

		return *this;
	}

};

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		fraction p(a, b);
		
		while (true)
		{
			int i = p.denom / p.nom;
			if (p.denom%p.nom)
			{
				p -= fraction(1, i + 1);
			}
			else
			{
				printf("%d\n", i);
				break;
			}

		}
	}
}
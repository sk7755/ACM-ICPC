#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

class student
{
public:
	char name[11];
	int k;
	int e;
	int m;

	student(char* name, int k, int e, int m) : k(k), e(e), m(m)
	{
		strcpy(this->name, name);
	}
};

int mycmp(student* a, student* b)
{
	if (a->k == b->k)
	{
		if (a->e == b->e)
		{
			if (a->m == b->m)
			{
				if (strcmp(a->name, b->name) < 0)
					return 1;
				else
					return 0;
			}
			return a->m > b->m;
		}
		return a->e < b->e;
	}

	return a->k > b->k;
}

int main()
{
	student* a[100000];

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		char name[11];
		int k, e, m;
		scanf("%s %d %d %d", name, &k, &e, &m);

		a[i] = new student(name, k, e,m);
	}

	sort(a, a + n, mycmp);

	for (int i = 0; i < n; i++)
		printf("%s\n", a[i]->name);

	return 0;
}
#include <cstdio>
#include <cstring>

typedef class bt* nptr;

class bt
{
public:
	char name[51];
	int n;
	nptr left, right;

	bt(const char name[]) : n(1), left(NULL), right(NULL)
	{
		strcpy(this->name, name);
	}
};

int main()
{
	int n;
	scanf("%d", &n);

	char name[51];

	scanf("%s", name);
	nptr root = new bt(name);
	
	int max = 1;
	nptr max_node = root;

	for (int i = 1; i < n; i++)
	{
		scanf("%s", name);
		nptr cur = root;
		nptr* pre = NULL;
		while (cur)
		{
			int cmp = strcmp(cur->name, name);

			if (cmp == 0)
				break;
			else if (cmp >0)
				pre = &(cur->left),cur = cur->left;
			else
				pre = &(cur->right), cur = cur->right;
		}
		if (cur)
			cur->n++;
		else
			cur = new bt(name), *pre = cur;

		if (cur->n > max || (cur->n == max && strcmp(cur->name, max_node->name)<0))
		{
			max = cur->n;
			max_node = cur;
		}
	}

	printf("%s\n", max_node->name);

	return 0;
}
#include <cstdio>

typedef struct NODE* nptr;

struct NODE
{
	int key;
	int n;
	int XOR;
	nptr left, right;
};

nptr root = NULL;

void insert(int key)
{
	nptr x = root, y = NULL;
	nptr pnew = new NODE;
	pnew->key = key;
	pnew->n = 1;
	pnew->XOR = key;
	pnew->left = pnew->right = NULL;

	while (x)
	{
		x->n++;
		x->XOR ^= key;
		y = x;
		if (x->key < key)
			x = x->right;
		else
			x = x->left;
	}

	if (!y)
		root = pnew;
	else
	{
		if (y->key < key)
			y->right = pnew;
		else
			y->left = pnew;
	}
}

int print(int k, nptr x)
{
	if (!x)
		return 0;
	if (x->n < k)
		k = x->n;

	int ret = 0;
	if (x->right)
	{
		if (x->right->n < k)
		{
			k -= x->right->n;
			ret ^= x->right->XOR;
		}
		else
			return print(k, x->right);
	}

	if(k)
	{
		k--;
		ret ^= x->key;
	}
	if (k)
		ret ^= print(k, x->left);

	return ret;
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		root = NULL;
		int q, k;
		scanf("%d %d", &q, &k);
		while (q--)
		{
			char op[10];
			scanf("%s", op);
			if (op[0] == 'i')
			{
				int key;
				scanf("%d", &key);
				insert(key);
			}
			else
			{
				printf("%d\n", print(k, root));
			}
		}
	}
}
#include <cstdio>

typedef struct node* nptr;

struct node
{
	int key;
	nptr left, right;

	node(int key, nptr left = NULL, nptr right = NULL) :key(key), left(left), right(right)
	{}
};

void post_order(nptr v);
nptr make_bt(int p_l, int p_r, int i_l, int i_r);

int preorder[1000];
int inorder[1000];

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++)
			scanf("%d", &preorder[i]);
		for (int i = 0; i < n; i++)
			scanf("%d", &inorder[i]);

		nptr root = make_bt(0, n - 1, 0, n - 1);

		post_order(root);
		printf("\n");
	}
}

nptr make_bt(int p_l, int p_r, int i_l, int i_r)
{
	if (p_l > p_r)
		return NULL;

	int key = preorder[p_l];

	int idx;
	for (int i = i_l; i <= i_r; i++)
	{
		if (inorder[i] == key)
		{
			idx = i;
			break;
		}
	}

	return new node(key, make_bt(p_l + 1, p_l + idx - i_l, i_l, idx - 1), make_bt(p_l + idx - i_l + 1, p_r, idx+1,i_r));
}

void post_order(nptr v)
{
	if (v->left)
		post_order(v->left);
	if (v->right)
		post_order(v->right);

	printf("%d ", v->key);
	delete v;
}
#include <cstdio>

typedef class node* nptr;

class node
{
public:
	char data;
	nptr l, r;

	node(char data, nptr l, nptr r) :data(data), l(l), r(r) {}
};

class tree
{
public:
	nptr root;
	nptr *head;
	int n;

	tree(int n) : n(n)
	{
		head = new nptr[n];
		for (int i = 0; i < n; i++)
			head[i] = new node('A' + i, NULL, NULL);

		root = head[0];
	}

	void update(char ch, char l, char r)
	{
		if (l != '.')
			head[ch - 'A']->l = head[l - 'A'];
		if (r != '.')
			head[ch - 'A']->r = head[r - 'A'];
	}

	void preorder(nptr cur)
	{
		printf("%c", cur->data);
		if (cur->l)
			preorder(cur->l);
		if (cur->r)
			preorder(cur->r);
		return;
	}
	void inorder(nptr cur)
	{
		if (cur->l)
			inorder(cur->l);
		printf("%c", cur->data);
		if (cur->r)
			inorder(cur->r);
		return;
	}

	void postorder(nptr cur)
	{
		if (cur->l)
			postorder(cur->l);
		if (cur->r)
			postorder(cur->r);
		printf("%c", cur->data);
		return;
	}

	~tree()
	{
		for (int i = 0; i < n; i++)
			delete head[i];
		delete[] head;
	}
};

int main()
{
	int n;

	scanf("%d", &n);
	
	tree t(n);

	for (int i = 0; i < n; i++)
	{
		getchar();
		char ch, l, r;
		scanf("%c %c %c", &ch, &l, &r);
		t.update(ch, l, r);
	}

	t.preorder(t.root);
	printf("\n");
	t.inorder(t.root);
	printf("\n");
	t.postorder(t.root);
	printf("\n");

	return 0;

}
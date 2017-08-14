#include <cstdio>
#include <cstdlib>

typedef struct node* nptr;

struct node
{
	int idx;
	nptr next;
	nptr pre;
};

int main()
{
	int n, m;
	nptr head = NULL;

	scanf("%d %d", &n, &m);

	for (int i = n; i >= 1; i--)
	{
		nptr pnew = (nptr)malloc(sizeof(node));
		pnew->idx = i;

		if (!head)
		{
			head = pnew;
			pnew->next = pnew;
			pnew->pre = pnew;
		}
		else
		{
			pnew->next = head;
			pnew->pre = head->pre;
			pnew->next->pre = pnew;
			pnew->pre->next = pnew;
			head = pnew;
		}
	}
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		int del;
		scanf("%d", &del);

		int move = 0;
		for (nptr p = head, q = head;; p = p->next, q = q->pre, move++)
		{
			if (p->idx == del)
			{
				p->next->pre = p->pre;
				p->pre->next = p->next;
				head = p->next;
				break;
			}
			else if (q->idx == del)
			{
				q->next->pre = q->pre;
				q->pre->next = q->next;
				head = q->next;
				break;
			}
		}
		ans += move;
	}

	printf("%d\n", ans);
}
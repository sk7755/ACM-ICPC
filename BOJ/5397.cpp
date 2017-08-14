#include <cstdio>
#include <cstring>

typedef struct NODE* nptr;

struct NODE
{
	char c;
	nptr next, pre;

	NODE(char c = '\0', nptr pre = NULL, nptr next = NULL) : c(c), pre(pre), next(next)
	{}
};

struct CURSOR
{
	nptr left, right;
};

void add_left(CURSOR& cursor, char c);
void cursor_left(CURSOR& cursor);
void cursor_right(CURSOR& cursor);
void delete_left(CURSOR& cursor);

int main()
{
	nptr front = new NODE;
	nptr rear = new NODE;

	char str[1000001];
	char result[1000001];

	int t;
	scanf("%d", &t);

	while (t--)
	{
		front->next = rear;
		rear->pre = front;
		CURSOR cursor = { front, rear };

		scanf("%s", str);
		int len = strlen(str);

		for (int i = 0; i < len; i++)
		{
			if (str[i] == '<')
				cursor_left(cursor);
			else if (str[i] == '>')
				cursor_right(cursor);
			else if (str[i] == '-')
				delete_left(cursor);
			else
				add_left(cursor, str[i]);

		}

		int k = 0;
		for (nptr p = front->next; p; p = p->next)
			result[k++] = p->c;

		printf("%s\n", result);
	}

	return 0;
}

void add_left(CURSOR& cursor, char c)
{
	nptr pnew = new NODE(c, cursor.left, cursor.right);
	(cursor.left)->next = pnew;
	(cursor.right)->pre = pnew;
	cursor.left = pnew;
}

void delete_left(CURSOR& cursor)
{
	if ((cursor.left)->c == '\0')
		return;

	nptr del = cursor.left;

	(del->pre)->next = del->next;
	(del->next)->pre = del->pre;

	cursor.left = del->pre;

	delete del;
}

void cursor_left(CURSOR& cursor)
{
	if ((cursor.left)->c == '\0')
		return;

	cursor.right = cursor.left;
	cursor.left = (cursor.left)->pre;
}

void cursor_right(CURSOR& cursor)
{
	if ((cursor.right)->c == '\0')
		return;

	cursor.left = cursor.right;
	cursor.right = (cursor.right)->next;
}
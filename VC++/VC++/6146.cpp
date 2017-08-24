//무척 비효율적으로 풀었으나..
//v번호에 구애받지 않는다
//구애받는것은 단지 노드 개수

#include <cstdio>

int IsThereNode(int v);
void dfs(int idx);

enum { size = 10000};

typedef struct node* nptr;

struct node
{
	int v;
	nptr link;
};

struct VERTEX
{
	int v;
	int parent;
	nptr head;
};

VERTEX vertex[size];
int node_cnt;
int visit_cnt;

int main()
{
	int k = 0;
	while (1)
	{
		k++;
		node_cnt = 0;
		int edge_cnt = 0;
		int flag = 1;
		while (1)
		{

			int u, v;
			scanf("%d %d", &u, &v);

			if (u == 0 && v == 0)
				break;
			if (u == -1 && v == -1)
				return 0;

			int u_idx = IsThereNode(u);
			if (!u_idx)
			{
				node_cnt++;
				vertex[node_cnt].v = u;
				vertex[node_cnt].parent = -1;
				vertex[node_cnt].head = NULL;
				u_idx = node_cnt;
			}

			edge_cnt++;
			nptr pnew = new node;
			pnew->v = v;
			pnew->link = vertex[u_idx].head;
			vertex[u_idx].head = pnew;
			

			int v_idx = IsThereNode(v);
			if (!v_idx)
			{
				node_cnt++;
				vertex[node_cnt].v = v;
				vertex[node_cnt].head = NULL;
				v_idx = node_cnt;
			}
			vertex[v_idx].parent = u;
		}
		if (node_cnt)
		{
			if (edge_cnt != node_cnt - 1)
				flag = 0;
			else
			{
				int root;
				for (int i = 1; i <= node_cnt; i++)
				{
					if (vertex[i].parent == -1)
					{
						root = i;
						break;
					}
				}
				//root로 부터 한번 돌려보고,
				visit_cnt = 0;
				dfs(root);

				if (visit_cnt != node_cnt)
					flag = 0;
			}
		}
		printf("Case %d is ",k);
		if (!flag)
			printf("not ");
		printf("a tree.\n");
	}
}

//Node가 있으면 Node index를 없으면 0을 반환하는 함수
int IsThereNode(int v)
{
	for (int i = 1; i <= node_cnt; i++)
	{
		if (vertex[i].v == v)
			return i;
	}
	return 0;
}

void dfs(int idx)
{
	vertex[idx].parent = -2;
	visit_cnt++;
	for (nptr p = vertex[idx].head; p; p = p->link)
	{
		int i = IsThereNode(p->v);
		if (vertex[i].parent != -2)
			dfs(i);
	}
}
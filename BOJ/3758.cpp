#include <cstdio>
#include <algorithm>

using namespace std;

class score
{
public:
	int id;
	int total;
	int cnt;
	int last;

	score() : id(0), total(0), cnt(0), last(0)
	{
	}
};

int mycmp(score* a, score* b)
{
	if (a->total == b->total)
	{
		if (a->cnt == b->cnt)
		{
			return a->last < b->last;
		}
		return a->cnt < b->cnt;
	}

	return a->total > b->total;
}

int main()
{
	int t;

	scanf("%d", &t);

	score* team[101];

	for (int i = 1; i <= 100; i++)
		team[i] = new score;

	while (t--)
	{
		int n, k, id, m;
		int score_board[101][101] = { 0, };
		scanf("%d %d %d %d", &n, &k, &id, &m);

		for (int i = 1; i <= m;i++)
		{
			int ID, j, s;
			scanf("%d %d %d", &ID, &j, &s);

			team[ID]->id = ID;
			if (score_board[ID][j] < s)
			{
				team[ID]->total += s - score_board[ID][j];
				score_board[ID][j] = s;
			}
			team[ID]->last = i;
			team[ID]->cnt++;
		}

		sort(team+1, team + n+1, mycmp);

		for (int i = 1; i <= n; i++)
		{
			if (team[i]->id == id)
				printf("%d\n", i);
			team[i]->id = team[i]->total = team[i]->cnt = team[i]->last = 0;
		}
	}

	return 0;
}
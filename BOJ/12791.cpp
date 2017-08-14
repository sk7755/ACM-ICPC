#include <cstdio>
#include <cstring>

typedef struct node* nptr;

struct node
{
	char* name;
	nptr link;

	node(const char* name = NULL, nptr link = NULL) : link(link)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

	~node()
	{
		delete[] name;
	}
};

void insert_data();

nptr head[2017] = { 0, };

int main()
{
	fprintf(stdin,"1234");
	char tamp[100];
	scanf("%s", tamp);
	printf("%s\n",tamp);

	insert_data();
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int s, e;
		scanf("%d %d", &s, &e);

		int cnt = 0;
		for (int i = s; i <= e; i++)
		{
			for (nptr p = head[i]; p; p = p->link)
				cnt++;
		}
		printf("%d\n", cnt);
		for (int i = s; i <= e; i++)
		{
			for (nptr p = head[i]; p; p = p->link)
				printf("%d %s\n", i,p->name);
		}
	}
}

void insert_data()
{
	head[1967] = new node("DavidBowie", head[1967]);
	head[1969] = new node("SpaceOddity", head[1969]);
	head[1970] = new node("TheManWhoSoldTheWorld", head[1970]);
	head[1971] = new node("HunkyDory", head[1971]);
	head[1972] = new node("TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars", head[1972]);
	head[1973] = new node("PinUps", head[1973]);
	head[1973] = new node("AladdinSane", head[1973]);
	head[1974] = new node("DiamondDogs", head[1974]);
	head[1975] = new node("YoungAmericans", head[1975]);
	head[1976] = new node("StationToStation", head[1976]);
	head[1977] = new node("Heroes", head[1977]);
	head[1977] = new node("Low", head[1977]);
	head[1979] = new node("Lodger", head[1979]);
	head[1980] = new node("ScaryMonstersAndSuperCreeps", head[1980]);
	head[1983] = new node("LetsDance", head[1983]);
	head[1984] = new node("Tonight", head[1984]);
	head[1987] = new node("NeverLetMeDown", head[1987]);
	head[1993] = new node("BlackTieWhiteNoise", head[1993]);
	head[1995] = new node("1.Outside", head[1995]);
	head[1997] = new node("Earthling", head[1997]);
	head[1999] = new node("Hours", head[1999]);
	head[2002] = new node("Heathen", head[2002]);
	head[2003] = new node("Reality", head[2003]);
	head[2013] = new node("TheNextDay", head[2013]);
	head[2016] = new node("BlackStar", head[2016]);
}

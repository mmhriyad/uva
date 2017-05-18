//558 - Wormholes

#include <stdio.h>

#define MAXN 1000
#define MAXE 2000
#define INF (1<<30)

int N, E;

typedef struct
{
	int source, dest, cost;
}t_edgelist;

t_edgelist edges[MAXE];
int parent[MAXN];

int cost[MAXN];

void init()
{
	int i, j;

	for (i = 0; i < N; ++i)
	{
		cost[i] = INF;
		parent[i] = -1;
	}
}

bool bellman(int source)
{
	cost[source] = 0;
	int i, j, s, d, c;
	bool updated;
	for (i = 0; i < N; ++i)
	{
		updated = false;
		for (j = 0; j < E; ++j)
		{
			s = edges[j].source;
			d = edges[j].dest;
			c = edges[j].cost;
			if (cost[s] != INF && cost[s] + c < cost[d])
			{
				if (parent[d] == s)
					return true;
				cost[d] = cost[s] + c;
				parent[d] = s;
				updated = true;
			}
		}
		if (!updated)
			return false;
	}

	for (j = 0; j < E; ++j)
	{
		s = edges[j].source;
		d = edges[j].dest;
		c = edges[j].cost;
		if (cost[s] != INF && cost[s] + c < cost[d])
		{
			cost[d] = cost[s] + c;
			return true;
		}
	}
	return false;

}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int S, D;
	int Testcases, caseno;
	int i, a, b, c;
	scanf("%d", &Testcases);
	N = E = 0;
	for (caseno = 1; caseno <= Testcases; ++caseno)
	{
		scanf("%d %d", &N, &E);
		init();
		for (i = 0; i < E; ++i)
		{
			scanf("%d %d %d", &a,  &b, &c);
			edges[i].source = a;
			edges[i].dest = b;
			edges[i].cost = c;
		} // input end

		S = 0;
		D = 1;

		if (N == 1 || E == 0 || !bellman(S))
			printf("not possible\n");
		else
			printf("possible\n");
	}

	return 0;
}
//558 - Wormholes

#include <stdio.h>

#define MAXN 1000
#define MAXE 9000
#define INF (1<<30)

int N, E;

typedef struct
{
	int source, dest, cost;
}t_edgelist;

t_edgelist edges[MAXE];
int parent[MAXN], power[MAXN];

int cost[MAXN];

void init()
{
	int i, j;

	for (i = 0; i < N; ++i)
	{
		cost[i] = -INF;
		parent[i] = -1;
		power[i] = 0;
	}
}

bool bellman(int source, int dest)
{
	if (source == dest)
		return true;
	cost[source] = 100;
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

			if (cost[s] != -INF && power[d] != INF)
			{
				if (power[s] == INF || cost[s] == INF)
				{
					updated = true;
					power[d] = INF;
					cost[d] = INF;
					parent[d] = s;
				}
				else if (cost[s] + power[d] > 0 && cost[s] + power[d] > cost[d])
				{
					updated = true;
					
					if (parent[d] == s)
					{
						power[d] = INF;
						cost[d] = INF;
					}
					else
					{
						parent[d] = s;
						cost[d] = cost[s] + power[d];
					}
				}
			}
		}
		if (cost[dest] > 0)
			return true;
		if (!updated)
			return false;
	}

	return false;

}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int S, D;
	
	int i, a, b, c, j;
	
	N = E = 0;
	while (scanf("%d", &N) == 1)
	{
		if (N < 0)
			break;
		init();
		E = 0;
		for (i = 0; i < N; ++i)
		{
			scanf("%d %d", &a, &b);
			power[i] = a;
			for (j = 0; j < b; ++j)
			{
				scanf("%d", &c);
				edges[E].source = i;
				edges[E].dest = c - 1;
				edges[E].cost = a;
				++E;
			}
		}

		S = 0;
		D = 1;

		if (!bellman(0, N-1))
			printf("hopeless\n");
		else
			printf("winnable\n");
	}

	return 0;
}
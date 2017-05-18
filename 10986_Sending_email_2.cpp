//10986_Sending_email.cpp
//bellmanford no use : time limit
#include <stdio.h>

#define MAXN 20000
#define MAXE 50000
#define INF (1<<30)

int N, E, Eact;

typedef struct
{
	int source, dest, cost;
}t_edgelist;

t_edgelist edges[MAXE], edges_min[MAXE];

int arr[MAXN][MAXN];
int cost[MAXN];

void init()
{
	int i, j;
	Eact = 0;
	for (i = 0; i < N; ++i)
	{
		cost[i] = INF;
		for (j = 0; j < N; ++j)
		{
			arr[i][j] = 0;
		}
	}
}

void bellman(int source)
{
	cost[source] = 0;
	int i, j, s, d, c;
	bool updated;
	for (i = 0; i < N; ++i)
	{
		updated = false;
		for (j = 0; j < Eact; ++j)
		{
			s = edges_min[j].source;
			d = edges_min[j].dest;
			c = edges_min[j].cost;
			if (cost[s] != INF && cost[s] + c < cost[d])
			{
				cost[d] = cost[s] + c;
				updated = true;
			}
			else if (cost[d] != INF && cost[d] + c < cost[s])
			{
				cost[s] = cost[d] + c;
				updated = true;
			}
		}
		if (!updated)
			break;
	}
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
		scanf("%d %d %d %d", &N, &E, &S, &D);
		init();
		for (i = 0; i < E; ++i)
		{
			scanf("%d %d %d", &a,  &b, &c);
			edges[i].source = a;
			edges[i].dest = b;
			edges[i].cost = c;
			if (arr[a][b] == 0 || arr[a][b] > c)
			{
				arr[a][b] = arr[b][a] = c;
			}
		} // input end
		Eact = 0;
		for (i = 0; i < E; ++i)
		{
			a = edges[i].source;
			b = edges[i].dest;
			c = edges[i].cost;
			if (arr[a][b] == c)
			{
				edges_min[Eact].source = a;
				edges_min[Eact].dest = b;
				edges_min[Eact].cost = c;
				++Eact;
			}
		}

		bellman(S);

		printf("Case #%d: ", caseno);
		if (cost[D] == INF)
			printf("unreachable\n");
		else
			printf("%d\n", cost[D]);
	}

	return 0;
}
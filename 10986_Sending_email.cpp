//10986_Sending_email.cpp

#include <stdio.h>

#define MAXN 20000
#define MAXE 50000
#define INF (1<<30)

int N, E;

typedef struct
{
	int source, dest, cost;
}t_edgelist;

t_edgelist edges[MAXE];

int cost[MAXN];

void init()
{
	int i, j;

	for (i = 0; i < N; ++i)
	{
		cost[i] = INF;
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
		for (j = 0; j < E; ++j)
		{
			s = edges[j].source;
			d = edges[j].dest;
			c = edges[j].cost;
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
		} // input end


		bellman(S);

		printf("Case #%d: ", caseno);
		if (cost[D] == INF)
			printf("unreachable\n");
		else
			printf("%d\n", cost[D]);
	}

	return 0;
}
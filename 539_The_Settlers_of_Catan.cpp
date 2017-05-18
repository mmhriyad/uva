#include <stdio.h>

#define MAXN 25

int nodes[MAXN];
int edges[MAXN][MAXN + 1];

bool taken[MAXN][MAXN];


int max_count = 0;

void backtrack(int u, int count)
{
	if (count > max_count)
		max_count = count;

	nodes[u] = count;
	int i, l = edges[u][0], v;
	for (i = 1; i <= l; ++i)
	{
		v = edges[u][i];
		if (!taken[u][v])
		{
			taken[u][v] = taken[v][u] = true;
			backtrack(v, count + 1);
			taken[u][v] = taken[v][u] = false;
		}
	}
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int N, E, i, a, b;
	while (scanf("%d %d", &N, &E) == 2)
	{
		if (N == 0 && E == 0)
			return 0;
		for (i = 0; i < N; ++i)
		{
			nodes[i] = 0;
			edges[i][0] = 0;
		}
		for (i = 0; i < E; ++i)
		{
			scanf("%d %d", &a, &b);
			edges[a][++edges[a][0]] = b;
			edges[b][++edges[b][0]] = a;
			taken[a][b] = taken[b][a] = false;
		}

		max_count = 0;
		for (i = 0; i < N; ++i)
		{
			backtrack(i, 0);
		}

		printf("%d\n", max_count);
	}
	return 0;
}
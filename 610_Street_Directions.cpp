#include <stdio.h>

#define MAXN 1001
#define MAXE (MAXN * (MAXN - 1))

#define MIN(x,y) ( x < y ? x : y)

int edgelist[MAXN][MAXN + 1];
int N, M;
int parent[MAXN], low[MAXN], disc[MAXN];
bool visited[MAXN], bedges[MAXN][MAXN];
int edges[MAXE][2], nedges = 0;


void dfs(int u, int total)
{
	disc[u] = low[u] = total;
	visited[u] = true;
	int i, l, v;
	l = edgelist[u][0];
	for (i = 1; i <= l; i++)
	{
		v = edgelist[u][i];
		if (!visited[v])
		{
			parent[v] = u;
			edges[nedges][0] = u;
			edges[nedges][1] = v;
			++nedges;
			bedges[u][v] = true;
			dfs(v, total + 1);
			
			low[u] = MIN(low[u], low[v]);
			if (low[v] > disc[u]) //bridge
			{
				edges[nedges][0] = v;
				edges[nedges][1] = u;
				++nedges;
				bedges[v][u] = true;
			}
		} //end if
		else if (v != parent[u])
		{
			low[u] = MIN(low[u], disc[v]);
			if (!bedges[v][u])
			{
				edges[nedges][0] = u;
				edges[nedges][1] = v;
				++nedges;
				bedges[u][v] = true;
			}
		}
	} // end for
}

void print_edges()
{
	int i, j;
	for (i = 0; i < nedges; i++)
	{
		printf("%d %d\n", edges[i][0], edges[i][1]);
	}
	//for (i = 1; i <= N; i++)
	//{
	//	for (j = 1; j <= N; j++)
	//	{
	//		if (bedges[i][j])
	//		{
	//			printf("%d %d\n", i, j);
	//		}
	//	}
	//}
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int i, j, case_no = 0, a, b;
	while (scanf("%d %d", &N, &M) == 2)
	{
		if (N == 0 && M == 0)
			break;

		for (i = 1; i <= N; i++)
		{
			parent[i] = low[i] = disc[i] = -1;
			visited[i] = false;
			edgelist[i][0] = 0;
			for (j = 1; j <= N; j++)
				bedges[i][j] = false;
		}

		for (i = 0; i < M; i++)
		{
			scanf("%d %d", &a, &b);
			edgelist[a][++edgelist[a][0]] = b;
			edgelist[b][++edgelist[b][0]] = a;
		}
		nedges = 0;
		dfs(1, 1);
		printf("%d\n\n", ++case_no);
		print_edges();
		printf("#\n");
	}
	
	return 0;
}
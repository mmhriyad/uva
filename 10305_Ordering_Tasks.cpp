#include "stdio.h"
#define MAX 200

int dis[MAX], fin[MAX], path[MAX];
int M, N, discovered, added;
bool graph[MAX][MAX];

void visit(int node)
{
	dis[node] = ++discovered;
	for(int i=1; i<=N; i++)
	{
		if(graph[node][i] && dis[i]<0)
		{
			visit(i);
		}
	}
	fin[node] = ++discovered;
	path[added--] = node;
}

int main()
{
	int i, j, a, b, count=0;
	for(;;)
	{
		scanf("%d %d", &N, &M);
		if(N == 0 && M == 0) return 0;
		//if(count>0) printf("\n");
		added = N;

		for(a=1; a<=N; a++)
		{
			dis[a] = -1;
			fin[a] = -1;
			for(b=1; b<=N; b++)
				graph[a][b] = false;
		}

		for(i=1; i<=M; i++)
		{
			scanf("%d %d", &a, &b);
			graph[a][b] = true;
		}

		for(i=1; i<=N; i++)
		{
			if(dis[i]<0)
				visit(i);
		}

		for(i=1; i<=N; i++)
		{
			printf("%d", path[i]);
			if(i<N) printf(" ");
		}
		printf("\n");
		count++;
	}
	return 0;
}
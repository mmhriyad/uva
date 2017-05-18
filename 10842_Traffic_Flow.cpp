#include <stdio.h>
#include <stdlib.h>

#define MAXPATHS 10001
#define MAXNODES 101

typedef struct
{
	int s, d, cost;
}path;
path p[MAXPATHS];

int parent[MAXNODES];

int M, N, T;

void init()
{
	int i;
	for(i=0; i<=M; i++)
		parent[i] = i;
}

int findParent(int i)
{
	if(parent[i] == i)
		return i;
	return findParent(parent[i]);
}

bool join(int a, int b)
{
	a = findParent(a);
	b = findParent(b);
	if(a == b)
		return false;
	if(a<b)
		parent[b] = a;
	else
		parent[a] = b;
	return true;
}

int sortf(const void *a, const void *b)
{
	path *p1 = (path *)a;
	path *p2 = (path *)b;
	return (p2->cost - p1->cost); //decreasing order
}

int main()
{
	freopen("input.txt", "r", stdin);
	int i, max_cost, min_edge, caseno;
	scanf("%d", &T);
	
	for(caseno=1; caseno<=T; caseno++)
	{
		scanf("%d %d", &M, &N);
		init();
		for(i=0; i<N; i++)
			scanf("%d %d %d", &p[i].s, &p[i].d, &p[i].cost);
		
		qsort(p, N, sizeof(path), sortf);

		max_cost = 0;
		for(i=0; i<N; i++)
		{
			if(join(p[i].s, p[i].d))
			{
				max_cost += p[i].cost;
				min_edge = p[i].cost;
			}
		}

		printf("Case #%d: %d\n", caseno, min_edge);
	}
}

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
int taken_edges[MAXPATHS], taken_edges_c;

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
	return (p1->cost - p2->cost);
}

int main()
{
	freopen("input.txt", "r", stdin);
	int i, j, min_cost, min_cost2, cost, taken = 0;
	scanf("%d", &T);
	
	while(T--)
	{
		scanf("%d %d", &M, &N);
		init();
		for(i=0; i<N; i++)
			scanf("%d %d %d", &p[i].s, &p[i].d, &p[i].cost);
		
		qsort(p, N, sizeof(path), sortf);

		min_cost = 0;
		taken_edges_c = 0;
		for(i=0; i<N; i++)
		{
			if(join(p[i].s, p[i].d))
			{
				min_cost += p[i].cost;
				taken_edges[taken_edges_c] = i;
				taken_edges_c++;
			}
		}
		min_cost2 = 99999999;
		for(j=0; j<taken_edges_c; j++)
		{
			cost = 0;
			init();
			taken = 0;
			for(i=0; i<N; i++)
			{
				if(i != taken_edges[j])
				{
					if(join(p[i].s, p[i].d))
					{
						cost += p[i].cost;
						taken++;
					}
				}
			}
			if(taken == M-1)
			{
				min_cost2 = (min_cost2 > cost ? cost : min_cost2);
				if(min_cost2 == min_cost)
					break;
			}
		}

		printf("%d %d\n", min_cost, min_cost2);
	}
}

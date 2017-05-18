#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAXP 501

typedef struct
{
	int x, y, index;
}point;
point p[MAXP];

typedef struct
{
	point *a;
	point *b;
	double dist;
}edge;

edge e[MAXP*MAXP];

int S, P, E;

int sortf(const void *a, const void *b)
{
	edge *e1 = (edge *)a;
	edge *e2 = (edge *)b;
	return e1->dist - e2->dist;
}

bool taken[MAXP];
int parent[MAXP];

void init()
{
	int i;
	for (i = 0; i < P; i++)
	{
		parent[i] = i;
		taken[i] = false;
	}
}

int getparent(int node)
{
	while (parent[node] != node)
	{
		node = parent[node];
	}
	return node;
}

bool join(int a, int b)
{
	int pa, pb;
	pa = getparent(a);
	pb = getparent(b);
	if (pa == pb)
		return false;
	else
	{
		taken[a] = taken[b] = true;
		if (pa > pb)
			parent[pa] = pb;
		else
			parent[pb] = pa;
		
		return true;
	}
}

int main()
{
//	freopen("inp.txt", "r", stdin);
	int T, cn, x, y, i, j, current, target;
	scanf("%d", &T);
	while (T--)
	{
		E = 0;
		scanf("%d %d", &S, &P);
		init();
		for (i = 0; i < P; i++)
		{
			scanf("%d %d", &x, &y);
			p[i].x = x;
			p[i].y = y;
			p[i].index = i;

			for (j = (i - 1); j >= 0; j--)
			{
				e[E].a = &p[i];
				e[E].b = &p[j];
				e[E++].dist = hypot( (double)(p[i].x - p[j].x), (double)(p[i].y - p[j].y) );
			}
		}

		qsort(e, E, sizeof(edge), sortf);

		current = 0;
		target = P - S;
		for (i = 0; i < E && current < target; i++)
		{
			if (join(e[i].a->index, e[i].b->index))
				current++;
		}

		printf("%.2lf\n", e[i - 1].dist);
	}
	return 0;
}
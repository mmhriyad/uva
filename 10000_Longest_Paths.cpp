/*
10000_Longest_Paths.cpp
Author : Md. Mahbubul Huq (Riyad)
*/
#include <stdio.h>

#define MAXN 101
#define INF (1<<30)

#define __USE_BFS

int N, S, cn = 0, d[MAXN + 1];

#ifdef __USE_BFS

int arr[MAXN][MAXN + 1];
int queue[2*MAXN], ql = 0;
int added[MAXN];

void init()
{
	int i;
	for (i = 0; i <= N; i++)
	{
		arr[i][0] = 0;
		d[i] = 0;
		added[i] = 0;
	}
	ql = 0;
}
void enQ(int a)
{
	if (ql < MAXN)
	{
		queue[ql++] = a;
		++added[a];
	}
}

int deQ()
{
	int a = 0;
	if (ql > 0)
	{
		--ql;
		a = queue[ql];
		--added[a];
	}
	return a;
}

bool isEmptyQ()
{
	return ql == 0 ? true : false;
}

//runtime 0.013
void bfs()
{
	int i, u, v, l;
	int maxv, maxn;
	maxv = 0;
	maxn = S;
	enQ(S);
	while (!isEmptyQ())
	{
		u = deQ();
		if (added[u] == 0)
		{
			l = arr[u][0];
			for (i = 1; i <= l; i++)
			{
				v = arr[u][i];
				if (d[v] < d[u] + 1)
				{
					d[v] = d[u] + 1;
					enQ(v);

					if (d[v] > maxv)
					{
						maxv = d[v];
						maxn = v;
					}
					else if (d[v] == maxv)
					{
						if (maxn > v)
							maxn = v;
					}
				}
			} //end for
		} //endif
	}//end while

	printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", ++cn, S, maxv, maxn);
}

#else

typedef struct
{
	int s, d;
}edge;

edge e[MAXN * (MAXN / 2)];

int E;

//runtime 0.059
void bellman_ford()
{
	int i, j, u, v, max, maxn;
	for (i = 1; i <= N; i++)
		d[i] = INF;
	d[S] = 0;
	max = 0;
	maxn = S;
	for (i = 0; i < N-1; i++)
	{
		for (j = 0; j < E; j++)
		{
			v = e[j].d;
			u = e[j].s;
			
			if((d[v] == INF && d[v] > d[u] + 1) || (d[u] != INF && d[v] < d[u] + 1))
			{
				d[v] = d[u] + 1;
				if (d[v] > max)
				{
					max = d[v];
					maxn = v;
				}
				else if (d[v] == max)
				{
					if (v < maxn)
						maxn = v;
				}
			}
		}
	}

	printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", ++cn, S, max, maxn);
}
#endif

int main()
{
	//freopen("inp.txt", "r", stdin);
	int a, b;
	while ((scanf("%d", &N) == 1) && N)
	{
		scanf("%d", &S);
#ifdef __USE_BFS
		init();
#else
		E = 0;
#endif
		while (scanf("%d %d", &a, &b) == 2)
		{
			if (a == 0 && b == 0)
				break;
#ifdef __USE_BFS
			arr[a][++arr[a][0]] = b;
#else
			e[E].s = a;
			e[E].d = b;
			E++;
#endif
		}
#ifdef __USE_BFS
		bfs();
#else
		bellman_ford();
#endif
	}
	return 0;
}
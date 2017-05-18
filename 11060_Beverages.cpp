//11060 - Beverages
#include <stdio.h>
#include <string.h>

#define MAXN 101
#define MAXE 201
#define MAXC 55

bool arr[MAXN][MAXN];

typedef struct
{
	char name[MAXC];
	bool visited_d, visited_t;
	int d, f;
	int total_childs;
	int childs[MAXN];
	
}t_node;

t_node nodes[MAXN];

typedef struct
{
	int source, dest;
}t_edge;

t_edge edges[MAXE];

int N, E;

int get_index(char *bvg)
{
	int i;
	for (i = 0; i < N; ++i)
	{
		if (strcmp(nodes[i].name, bvg) == 0)
			return i;
	}
	return -1;
}

int count;

void dfs(int u)
{
	int i, l, v;
	
	nodes[u].visited_d = true;
	nodes[u].d = ++count;
	l = nodes[u].total_childs;

	for (i = 0; i < l; ++i)
	{
		v = nodes[u].childs[i];
		if (!nodes[v].visited_d)
		{
			dfs(v);
		}
	}
	nodes[u].f = ++count;
}

void topo_sort(int u)
{
	int i, l, v;

	nodes[u].visited_t = true;

	l = nodes[u].total_childs;

	for (i = 0; i < l; ++i)
	{
		v = nodes[u].childs[i];
		if (!nodes[v].visited_t)
		{
			topo_sort(v);
		}
	}
	
	printf(" %s", nodes[u].name);
}

void init()
{
	int i, j;
	for (i = 0; i < N; ++i)
	{
		nodes[i].total_childs = 0;
		nodes[i].visited_d = nodes[i].visited_t = false;
		for (j = 0; j < N; ++j)
			arr[i][j] = false;
	}
	count = 0;
}

int main()
{
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int i, a, b, j;
	int case_no;
	char bvg1[MAXC], bvg2[MAXC];
	case_no = 0;
	while (scanf("%d", &N) == 1)
	{
		init();
		gets(nodes[0].name);
		for (i = 0; i < N; ++i)
		{
			gets(nodes[i].name);
		}

		scanf("%d", &E);

		for (i = 0; i < E; ++i)
		{
			scanf("%s %s", bvg1, bvg2);
			a = get_index(bvg1);
			b = get_index(bvg2);
			edges[i].source = b;
			edges[i].dest = a;
			nodes[b].childs[nodes[b].total_childs++] = a;
			arr[b][a] = true;
			arr[a][b] = true;
		}

		//dfs
		for (i = 0; i < N; ++i)
		{
			if (!nodes[i].visited_d)
			{
				dfs(i);
			}
		}

		//add edge
		for (i = 0; i < N-1; ++i)
		{
			for (j = i; j < N; ++j)
			{
				if (!arr[i][j] && (
					(nodes[i].d > nodes[j].d && nodes[i].f > nodes[j].f) ||
					(nodes[i].d < nodes[j].d && nodes[i].f < nodes[j].f)))
				{
					nodes[j].childs[nodes[j].total_childs++] = i;
				}
			}
		}

		//toplogical sort
		printf("Case #%d: Dilbert should drink beverages in this order:", ++case_no);
		for (i = 0; i < N; ++i)
		{
			if (!nodes[i].visited_t)
			{
				topo_sort(i);
			}
		}
		printf(".\n");
	}

	return 0;
}
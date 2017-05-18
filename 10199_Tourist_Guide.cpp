#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 100
#define MAX_NAME_LEN 35

#define MIN(x, y) (x < y ? x : y)

char places[MAXN][MAX_NAME_LEN];

int arr_adj[MAXN][MAXN + 1];

int N, E, camera_found = 0, time = 0;
int dis[MAXN], fin[MAXN], low[MAXN], parent[MAXN];
bool visited[MAXN], has_camera[MAXN];

void dfs(int u)
{
	int nchild = 0;
	int i, l, v;
	++time;
	dis[u] = low[u] = time;
	visited[u] = true;
	l = arr_adj[u][0];
	for (i = 1; i <= l; i++)
	{
		v = arr_adj[u][i];
		if (!visited[v])
		{
			++nchild;
			parent[v] = u;
			dfs(v);

			low[u] = MIN(low[u], low[v]);

			if (!has_camera[u])
			{
				if (parent[u] == -1)
				{
					if (nchild > 1)
					{
						has_camera[u] = true;
						++camera_found;
					}
				}
				else if (low[v] >= dis[u])
				{
					has_camera[u] = true;
					++camera_found;
				}
			}
		}
		else if (parent[u] != v)
		{
			low[u] = MIN(low[u], dis[v]);
		}
	}
	fin[u] = ++time;
}

int sortf(const void *a, const void *b)
{
	const char *citya = (const char *)a;
	const char *cityb = (const char *)b;

	return strcmp(citya, cityb);
}

int get_index(char *city)
{
	int i;
	for (i = 0; i < N; i++)
	{
		if (!strcmp(city, places[i]))
			return i;
	}
	return -1;
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int case_no, i, j, a, b, map_no = 0;

	char citya[MAX_NAME_LEN], cityb[MAX_NAME_LEN];

	while (scanf("%d", &N) == 1 && N)
	{
		gets(places[0]);
		for (i = 0; i < N; i++)
		{
			gets(places[i]);
			arr_adj[i][0] = 0;
			dis[i] = fin[i] = low[i] = parent[i] = -1;
			visited[i] = has_camera[i] = false;
		}

		qsort(places, N, sizeof(places[0]), sortf);

		scanf("%d", &E);
		for (i = 0; i < E; i++)
		{
			scanf("%s %s", citya, cityb);
			a = get_index(citya);
			b = get_index(cityb);
			arr_adj[a][++arr_adj[a][0]] = b;
			arr_adj[b][++arr_adj[b][0]] = a;
		}
		camera_found = 0;
		time = 0;
		for (i = 0; i < N; i++)
		{
			if (!visited[i])
				dfs(i);
		}
		if (map_no > 0)
			printf("\n");
		printf("City map #%d: %d camera(s) found\n", ++map_no, camera_found);
		for (i = 0; i < N; i++)
		{
			if (has_camera[i])
				puts(places[i]);
		}
	}
	return 0;
}
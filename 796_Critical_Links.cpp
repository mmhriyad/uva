#include <stdio.h>

#define MAXN 2000

#define MIN(x, y) (x < y ? x : y)

int arr_adj[MAXN][MAXN + 1];
bool bridge[MAXN][MAXN];

int N, nbridges;

int dis[MAXN], low[MAXN], parent[MAXN];
bool visited[MAXN];

void dfs(int u, int time)
{
	int i, l, v;
	dis[u] = low[u] = time;
	visited[u] = true;
	l = arr_adj[u][0];
	for (i = 1; i <= l; i++)
	{
		v = arr_adj[u][i];
		if (!visited[v])
		{
			parent[v] = u;
			dfs(v, time + 1);

			low[u] = MIN(low[u], low[v]);

			if (low[v] > dis[u])
			{
				++nbridges;
				if (u < v)
					bridge[u][v] = true;
				else
					bridge[v][u] = true;
			}
		}
		else if (parent[u] != v)
			low[u] = MIN(low[u], dis[v]);
	}

}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int i, j, l, u, v;
	char inp[5000];
	while (scanf("%d", &N) == 1)
	{
		gets(inp);
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				bridge[i][j] = false;
			}
			gets(inp);
			j = 0;
			u = 0;
			while (inp[j] != ' ')
			{
				u = u * 10 + (inp[j] - '0');
				j++;
			}

			dis[u] = parent[u] = low[u] = -1;
			visited[u] = false;

			while (inp[j++] != '(');
			l = 0;
			while (inp[j] != ')')
			{
				l = l * 10 + (inp[j] - '0');
				j++;
			}
			arr_adj[u][0] = 0;

			if (l == 0)
				continue;

			while (inp[j++] != ' ');

			while (inp[j])
			{
				v = 0;
				while (inp[j] >= '0' && inp[j] <= '9')
				{
					v = v * 10 + (inp[j] - '0');
					j++;
				}
				
				arr_adj[u][++arr_adj[u][0]] = v;

				if (!inp[j])
					break;

				while (inp[j] < '0' || inp[j] > '9')
				{
					++j;
					if (!inp[j])
						break;
				}
			} // end of while (inp[j])
		}// for (i = 0; i < N; i++) input taken finish

		//gets(inp); // blank line

		nbridges = 0;

		for (i = 0; i < N; i++)
		{
			if (!visited[i])
			{
				dfs(i, 1);
			}
		}

		printf("%d critical links\n", nbridges);

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (bridge[i][j])
					printf("%d - %d\n", i, j);
			}
		}
		printf("\n");
	}
}

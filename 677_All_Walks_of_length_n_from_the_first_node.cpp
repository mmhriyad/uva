#include <stdio.h>

int arr[10][10];
int path[10];
bool visited[10] = { false, };
int N, L;
int totalfound = 0;

void dfs(int u, int len)
{
	int i;

	if (len == L)
	{
		printf("(1");
		for (i = 1; i <= len; ++i)
			printf(",%d", path[i] + 1);
		printf(")\n");
		++totalfound;
		return;
	}
	visited[u] = true;
	for (i = 0; i < N; ++i)
	{
		if (arr[u][i] == 1 && !visited[i])
		{
			path[len + 1] = i;
			dfs(i, len + 1);
		}
	}
	visited[u] = false;
}


int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int i, k;
	path[0] = 0;
	while (scanf("%d", &N) == 1)
	{
		if (N == -9999)
		{
			printf("\n");
			continue;
		}
		
		scanf("%d", &L);
		for (i = 0; i < N; ++i)
		{
			for (k = 0; k < N; ++k)
				scanf("%d", &arr[i][k]);
		}
		totalfound = 0;
		dfs(0, 0);
		if (totalfound == 0)
			printf("no walk of length %d\n", L);
	}
	return 0;
}
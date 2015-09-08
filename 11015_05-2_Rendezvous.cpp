/*
11015_05-2_Rendezvous.cpp
Author : Md. Mahbubul Huq (Riyad)
*/
#include <stdio.h>

#define MAXN 23
#define INF (1<<30)

int main()
{
	//freopen("inp.txt", "r", stdin);
	int T = 1, arr[MAXN][MAXN], N, M, i, j, k, min, a, b, cost, minp;
	char members[MAXN][20];
	
	while (scanf("%d %d", &N, &M) == 2)
	{
		if (N == 0 && M == 0)
			break;
		gets(members[0]);
		for (i = 1; i <= N; i++)
		{
			gets(members[i]);
			
			for (j = 1; j <= N; j++)
				arr[i][j] = INF;
			
			arr[i][i] = 0;
		}

		for (i = 0; i < M; i++)
		{
			scanf("%d %d %d", &a, &b, &cost);
			if (arr[a][b] > cost)
				arr[a][b] = arr[b][a] = cost;
		}

		for (k = 1; k <= N; k++)
		{
			for (i = 1; i <= N; i++)
			{
				for (j = 1; j <= N; j++)
				{
					if (arr[i][j] > arr[i][k] + arr[k][j])
						arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}

		min = INF;
		for (j = 1; j <= N; j++)
		{
			cost = 0;
			for (i = 1; i <= N; i++)
			{
				cost += arr[i][j];
			}
			if (cost < min)
			{
				min = cost;
				minp = j;
			}
		}

		printf("Case #%d : %s\n", T++, members[minp]);
	}

	return 0;

}

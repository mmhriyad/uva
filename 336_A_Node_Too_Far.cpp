#include <stdio.h>
#include <string.h>

#define MAX 100
#define MAXVAL 999999

int arr[MAX][MAX];
int map[MAX];

int maxnodes = 0;

int getindex(int a, int insert)
{
	for(int i=0; i<MAX; i++)
	{
		if(map[i] == a)
			return i;
		if(map[i] == 0)
		{
			if(!insert) return -1;
			map[i] = a;
			maxnodes = i;
			return i;
		}
	}

}

int main()
{
	//freopen("input.txt", "r", stdin);
	int n, i, j, k, a, b, caseno=1, nrnodes, source, ttl, maxval;
	for(;;)
	{
		scanf("%d", &n);
		if(n == 0) return 0;
		
		memset(arr, MAXVAL, sizeof(arr));
		maxval = arr[0][0];
		
		for(i=0; i<MAX; i++)
		{
			for(j=0; j<MAX; j++)
			{
				arr[i][j] = MAXVAL;
			}
			arr[i][i] = map[i] = 0;
		}
			

		maxnodes = 0;

		for(i=0; i<n; i++)
		{
			scanf("%d %d", &a, &b);
			a = getindex(a, 1);
			b = getindex(b, 1);
			if(a != b)
				arr[a][b] = arr[b][a] = 1;
		}

		for(k=0; k<=maxnodes; k++)
		{
			for(i=0; i<=maxnodes; i++)
			{
				for(j=0; j<=maxnodes; j++)
				{
					if(arr[i][j] > arr[i][k] + arr[k][j])
						arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
		for(;;)
		{
			scanf("%d %d", &source, &ttl);
			if(source == 0 && ttl == 0) break;
			nrnodes = 0;
			a = getindex(source, 0);
			if(a == -1)
				nrnodes = maxnodes+1;
			else
			{
				for(i=0; i<=maxnodes; i++)
					if(arr[a][i] > ttl)
						nrnodes++;
			}
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", caseno++, nrnodes, source, ttl);
		}
	}
}
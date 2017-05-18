#include <stdio.h>

#define MAX_WEEKS 15
#define MAX_HOTELS 20

int pcost[MAX_HOTELS], rooms[MAX_HOTELS][MAX_WEEKS];

int main()
{
	int N, H, B, W, p, a, i, j;
	long long int total_cost;
	//freopen("input.txt", "r", stdin);
	while(scanf("%d %d %d %d", &N, &B, &H, &W) == 4)
	{
		for(i = 1; i<=H; i++)
		{
			scanf("%d", &pcost[i]);
			for(j=1; j<=W; j++)
			{
				scanf("%d", &rooms[i][j]);
			}
		}
		total_cost = 0;
		int min_cost = B+1;
		for(j=1; j<=W; j++)
		{
			for(i=1; i<=H; i++)
			{
				if(rooms[i][j] >= N)
				{
					if(pcost[i]*N < min_cost)
						min_cost = pcost[i]*N;
				}
			}
		}
		if(min_cost > B)
			printf("stay home\n");
		else
			printf("%d\n", min_cost);
	}
	return 0;
}
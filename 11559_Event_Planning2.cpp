#include <stdio.h>

int main()
{
	int N, H, B, W, p, a, i, j;
	int hcost, size, min_cost;
	//freopen("input.txt", "r", stdin);
	while(scanf("%d %d %d %d", &N, &B, &H, &W) == 4)
	{
		min_cost = B+1;
		for(i = 1; i<=H; i++)
		{
			scanf("%d", &hcost);
			for(j=1; j<=W; j++)
			{
				scanf("%d", &size);
				if(hcost < min_cost && size>=N)
					min_cost = hcost;
			}
		}
		min_cost *= N;
		if(min_cost > B)
			printf("stay home\n");
		else
			printf("%d\n", min_cost);
	}
	return 0;
}
#include <stdio.h>
#include <string.h>

#define MAXI 21
#define MAXV 201

int item[MAXI][MAXI];
int arr[MAXV][MAXI];

int T, nitems, M, C, max_amount;

bool possible;

void dp()
{
	int i, j, k;
	memset(arr, 0, sizeof(arr));
	for(i=1; i<=M; i++)
	{
		for(j=0; j<C; j++)
		{
			arr[i][j] = 0;
			for(k=1; k<=item[j][0]; k++)
			{
				if(item[j][k] <= i)
				{
					if(j == 0 && item[j][k] > arr[i][j])
						arr[i][j] = item[j][k];
					else if(i-item[j][k] > 0 && arr[i-item[j][k]][j-1] > 0)
					{
						if(item[j][k] + arr[i-item[j][k]][j-1] > arr[i][j])
							arr[i][j] = item[j][k] + arr[i-item[j][k]][j-1];
					}
				}
			}
		}
	}
}


int main()
{
	freopen("input.txt", "r", stdin);
	
	int i, j;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &M, &C);
		for(i=0; i<C; i++)
		{
			scanf("%d", &nitems);
			item[i][0] = nitems;
			for(j = 1; j <= nitems; j++)
				scanf("%d", &item[i][j]);
		}
		
		possible = false;
		dp();
		max_amount = arr[M][C-1];
		if(max_amount > 0)
			printf("%d\n", max_amount);
		else
			printf("no solution\n");
	}
}
#include <stdio.h>

#define NO_OF_COINS 5

long long int arr[7500][NO_OF_COINS+1];
int m = NO_OF_COINS;
int coins[NO_OF_COINS+1] = {0, 1, 5, 10, 25, 50};

int main()
{
	int N, i, j;
	
	int max = -1;

	for(j = 0; j <= m; j++)
		arr[0][j] = 1;

	while(scanf("%d", &N) == 1)
	{
		if(N > max)
		{
			for(i=max; i<=N; i++)
			{
				for(j=0; j<=m; j++)
				{
					if(i == 0) arr[i][j] = 1;
					else if(j == 0) arr[i][j] = 0;
					else
					{
						if(coins[j] > i)
							arr[i][j] = arr[i][j-1];
						else
							arr[i][j] = arr[i][j-1] + arr[i-coins[j]][j];
					}
				}
			}
			max = N;
		}
		printf("%lld\n", arr[N][m]);

	}
	return 0;
}
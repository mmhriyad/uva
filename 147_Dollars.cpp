#include <stdio.h>

#define NO_OF_COINS 11

long long int arr[30001][NO_OF_COINS+1];
int m = NO_OF_COINS;
int coins[NO_OF_COINS+1] = {0, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

int main()
{
	freopen("input.txt", "r", stdin);
	int N, i, j;
	float M;
	
	int max = 0;

	for(j = 0; j <= m; j++)
		arr[0][j] = 1;

	while(scanf("%f", &M) == 1 && M)
	{
		N = ((M * 1000)+1)/10;

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
		printf("%6.2f%17lld\n", M, arr[N][m]);

	}
	return 0;
}
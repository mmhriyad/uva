#include <stdio.h>
//not solved.
#define MAXN 505
#define INF 999999
#define MAXC 7

int ac[MAXN][MAXC] = {0,};
int coins[MAXC] = {0,5,10,20,50,100,200};

int min[MAXN], min_coin = 5;


int N;

void dp()
{
	int i, j, k;
	min[0] = 0;
	for(i=1; i<=N; i++)
	{
		min[i] = INF;
		for(j=0; j<MAXC; j++)
			ac[i][j] = ac[0][j];
	}

	for(i=min_coin; i<=N; i+=min_coin)
	{
		for(j=1; coins[j]<=i && j<MAXC; j++)
		{
			if(min[i] > (min[ i - coins[j] ] + 1))
			{
				if(ac[i-coins[j]][j] > 0)
				{
					min[i] = min[ i - coins[j] ] + 1;
					for(k=0; k<MAXC; k++)
						ac[i][k] = ac[ i - coins[j] ][k];
					ac[i][j] = ac[ i - coins[j] ][j] - 1;
				}
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	float M;

	for(;;)
	{
		ac[0][0] = 0;
		scanf("%d %d %d %d %d %d", &ac[0][1], &ac[0][2], &ac[0][3], &ac[0][4], &ac[0][5], &ac[0][6]);
		
		if(!ac[0][1] && !ac[0][2] && !ac[0][3] && !ac[0][4] && !ac[0][4] && !ac[0][6])
			return 0;
		
		scanf("%f", &M);
		N = ((M*1000)+1)/10;
		dp();
		printf("%d\n", min[N]);
	}
}

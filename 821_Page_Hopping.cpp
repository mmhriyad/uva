#include <stdio.h>

#define MAXNODES 105
#define INF 99999999

int main()
{
	int dist[MAXNODES][MAXNODES];
	int i,j,k, a, b, n=0, caseNo = 1;
	for(i=0; i<MAXNODES; i++)
	{
		for(j=0; j<MAXNODES; j++)
		{
			dist[i][j] = INF;
		}
	}
	for(;;)
	{
		scanf("%d %d", &a, &b);
		if(a==0 && b==0)
			return 0;
		else
		{
			for(i=1; i<=n; i++)
			{
				for(j=1; j<=n; j++)
				{
					dist[i][j] = INF;
				}
			}
			n = 0;
			for(;;)
			{
				dist[a][b] = 1;
				if(a>n) n = a;
				if(b>n) n = b;

				//cin>>a>>b;
				scanf("%d %d", &a, &b);
				if(a==0 && b==0)
					break;
			}

			for(k=1; k<=n; k++)
			{
				for(i=1; i<=n; i++)
				{
					for(j=1; j<=n; j++)
					{
						if(dist[i][j] > dist[i][k]+dist[k][j] && i!=j)
							dist[i][j] = dist[i][k]+dist[k][j];
					}
				}
			}

			int count = 0;
			double sum = 0;

			for(i=1; i<=n; i++)
			{
				for(j=1; j<=n; j++)
				{
					if(dist[i][j] != INF && i!=j)
					{
						sum += dist[i][j];
						count++;
					}
				}
			}
			
			printf("Case %d: average length between pages = %.3f clicks\n", caseNo++, (sum/count));

			

		}
	}

}
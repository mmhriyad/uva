#include <stdio.h>

long long int arr[30005][6];
int m = 5;
int coins[6] = {0, 1, 5, 10, 25, 50};

int main()
{
	int N, i, j;
	
	int max = -1;

	FILE * pFile;
	pFile = fopen ("357.txt","w");


	for(j = 0; j <= m; j++)
		arr[0][j] = 1;

	while(scanf("%d", &N) == 1)
	{
		if(N > max)
		{
			fprintf(pFile, "{");
			for(i=max; i<=N; i++)
			{
				fprintf(pFile, "{");
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
					fprintf(pFile, "%lld", arr[i][j]);
					if(j<m)
						fprintf(pFile, ",");
				}
				fprintf(pFile, "}");
				if(i<N)
					fprintf(pFile, ",");
				fprintf(pFile, "\n");
			}
			
			fprintf(pFile, "}\n");
			max = N;
		}
		fclose (pFile);

		if(arr[N][m] > 1)
			printf("There are %lld ways to produce %d cents change.\n", arr[N][m], N);
		else
			printf("There is only 1 way to produce %d cents change.\n", N);

	}
	return 0;
}
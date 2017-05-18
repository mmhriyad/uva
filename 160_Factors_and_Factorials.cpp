#include <stdio.h>
#include <string.h>

#define MAXN 25

int f[MAXN] = {2, 3, 5, 7, 11, 
			13, 17, 19, 23, 29, 
			31, 37, 41, 43, 47, 
			53, 59, 61, 67, 71, 
			73, 79, 83, 89, 97};

int arr[101][MAXN], foundpos[101] = {0,};

int main()
{
	int n, i, j, max = 1;
	int found=0, num;
	memset(arr, 0, sizeof(arr));

	for(;;)
	{
		scanf("%d", &n);
		if(!n) return 0;

		if(n > max)
		{
			for(i = max+1; i<=n; i++)
			{
				j = MAXN-1;
				num = i;
				while((j >= 0) & (num > 1))
				{
					if(num%f[j] == 0)
					{
						if(j>found)
							found = j;
						arr[i][j]++;
						num /= f[j];
					}
					else
					{
						j--;
					}
				}
				foundpos[i] = found;
				for(j=0; j<=foundpos[i]; j++)
					arr[i][j] += arr[i-1][j];
			}
			max = n;
		}
		
		printf("%3d! =", n);
		for(i=0; i<=foundpos[n]; i++)
		{
			if(i>0 && (i%15 == 0)) printf("\n      ");
			printf("%3d", arr[n][i]);
		}
		printf("\n");

	}
}
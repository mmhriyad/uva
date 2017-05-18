#include <stdio.h>
//#include <stdlib.h>

#define MAXN 10001
int arr[MAXN], N, M;

//int sortf(void const *a, void const *b)
//{
//	int *i1 = (int *)a;
//	int *i2 = (int *)b;
//	return *i1 - *i2;
//}

int main()
{
	freopen("input.txt", "r", stdin);
	int i,j, a, b, diff, min_diff = MAXN;

	while(scanf("%d", &N) == 1)
	{
		
		for(i=0; i<N; i++)
			scanf("%d", &arr[i]);
		scanf("%d", &M);

		//qsort(arr, N, sizeof(int), sortf);

		min_diff = 1000001;

		for(i=0; i<N-1; i++)
		{
			for(j=i+1; j<N; j++)
			{
				if(arr[i] + arr[j] == M)
				{
					diff = (arr[i] > arr[j]) ? (arr[i] - arr[j]) : (arr[j] - arr[i]);
					if(diff < min_diff)
					{
						min_diff = diff;
						if(arr[i] > arr[j])
						{
							a = arr[j];
							b = arr[i];
						}
						else
						{
							a = arr[i];
							b = arr[j];
						}
						break;
					}
				}
			}
		}

		printf("Peter should buy books whose prices are %d and %d.\n\n", a, b);
	}
}
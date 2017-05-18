#include <stdio.h>

int main()
{
	int arr[51], i, sum, avg, n, T=0;
	for(;;)
	{
		T++;
		scanf("%d", &n);
		if(n == 0) return 0;
		sum = 0;
		for(i=0; i<n; i++)
		{
			scanf("%d", &arr[i]);
			sum += arr[i];
		}
		avg = sum/n;
		sum = 0;
		for(i=0; i<n; i++)
		{
			if(arr[i]>avg)
				sum += (arr[i]-avg);
		}
		printf("Set #%d\nThe minimum number of moves is %d.\n\n", T, sum);

	}
	
}
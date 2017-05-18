#include "stdio.h"

int main()
{
	double sum, avg, posSum, negSum;
	int n, i;
	double arr[1000];

	for(;;)
	{
		sum=0,avg=0;
		scanf("%d", &n);
		if(n==0) break;

		for(i=0; i<n; i++)
		{
			scanf("%lf",&arr[i]);
			sum += arr[i];
		}
		avg = sum / n;

		posSum=0;
		negSum=0;
		for(i=0;i<n;i++)
		{
			if(arr[i] < avg)
				posSum += (long)((avg - arr[i])*100.0)/100.0;
			else
				negSum += (long)((arr[i] - avg)*100.0)/100.0;
		}
		printf("$%.2f\n", (posSum > negSum) ? posSum : negSum);
	}
	
	return 0;
}
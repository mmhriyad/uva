#include "stdio.h"

void getDivisors(int n)
{
	int maxlim = n, i;
	int found = 0;
	int sum=1;
	//printf("1 ");
	for(i=2; i<=maxlim; i++)
	{
		if(n%i == 0)
		{
			//printf("%d ", i);
			sum += i;
			if(!found && i<maxlim)
			{
				maxlim = n/i;
			}
			found++;
		}
	}
	//printf("\n");
	if(maxlim == n)
		printf("%5d  DEFICIENT\n", n);
	else if(sum == n)
		printf("%5d  PERFECT\n", n);
	else if(sum > n)
		printf("%5d  ABUNDANT\n", n);
	else if(sum < n)
		printf("%5d  DEFICIENT\n", n);
}

int main()
{
	int inp, a=0;
	for(;;)
	{
		scanf("%d", &inp);
		if(0==a)
			printf("PERFECTION OUTPUT\n");
		if(!inp) 
		{
			printf("END OF OUTPUT\n");
			return 0;
		}
		getDivisors(inp);
		a++;
	}
	return 0;
}
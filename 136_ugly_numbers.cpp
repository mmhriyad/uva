#include "stdio.h"

#define MAX 9999999

int arr[MAX];

bool isUgly(int i)
{
	if(i==1)
		return true;
	if(i%5==0)
	{
		if(i/5 < MAX && arr[i/5]==1) return true;
		return isUgly(i/5);
	}
	if(i%3==0)
	{
		if(i/3 < MAX && arr[i/3]==1) return true;
		return isUgly(i/3);
	}
	if(i%2==0)
	{
		if(i/2 < MAX && arr[i/2]==1) return true;
		return isUgly(i/2);
	}
	
	return false;
}

int main()
{
	int count=1, i=1;
	arr[1]=1;
	while(count<1500)
	{
		i++;
		if( (i%5==0) || (i%3==0) || (i%2==0) )
		{
			if( isUgly(i) )
			{
				count++;
				if(i<MAX)
					arr[i]=1;
			}
		}
	}

	printf("The 1500'th ugly number is %d.\n", i);
	//printf("The 1500'th ugly number is 859963392.\n");

	return 0;
}
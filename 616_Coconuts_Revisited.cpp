#include "iostream"
#include "stdio.h"
#include <math.h>  

using namespace std;

int main()
{
	long long int n, i, j, powv, max_lim, arr_pow[13] = {1,1,4,27,256,3125,46656,823543,16777216,
 387420489,10000000000,285311670611,8916100448256};
	//double inp;
	bool sol=false;

	for(;;)
	{
		cin>>n;
		if(n == -1) return 0;
		sol = false;
		//max_lim = sqrt((double)n)+1;
		max_lim = 7;
		for(i=max_lim; i>=2; i--)
		{
			//powv = pow((double)i,(double)i);
			powv = arr_pow[i];
			if((n+i-1)%powv == 0)
			{
				if(i%2==0) //even
				{
					if(((n+i-1)/powv)%i == i-1)
						sol = true;
				}
				else
				{
					if(((n+i-1)/powv)%i == 1)
						sol = true;
				}
			}
			if(sol) break;
		}
		if(sol)
			cout<<n<<" coconuts, "<<i<<" people and 1 monkey"<<endl;
		else
			cout<<n<<" coconuts, no solution"<<endl;

	}

	return 0;
}
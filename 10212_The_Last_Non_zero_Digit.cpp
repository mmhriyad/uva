#include "stdio.h"

/*
calculate (a^b)%c
(a^3)
*/
/*

*/
int mod(int a, int b, int c)
{
    if(b==0) return 1;
    
    if(b%2==0)
    {
        int x=mod(a,b/2,c);
        return (x*x)%c;
    }
    else return (a%c * mod(a,b-1,c))%c;
}

long long int fact(long long int a)
{
	if(a==1) return 1;
    
    else return a * fact(a-1);
    
}

long long int fact_mod(long long int a, long long int b)
{
    
	long long int res = 1, n, i;
	int divide_by = 1000;
	for(i=b; i<=a; i++)
	{
		n = i;
		/*
		if(n%10 == 0)
			n /= 10;
		*/
		while(n%10 == 0)
		{
			n /= 10;
		}
		//n %= divide_by;

		//res *= n;
		res = ( (res%divide_by) * (n%divide_by) );
		/*
		if(res%10 == 0)
			res /= 10;
		*/
		while(res%10 == 0)
		{
			res /= 10;
		}
		//res %= divide_by;
	}

	while(res%10 == 0)
	{
		res /= 10;
	}
	res %= 10;

	return res;
}

int main()
{
	long long int n, m;
	/*
	for(int i=1; i<1000; i++)
	{
		printf("fact %5d: %5lld\n", i, fact_mod(i, 1) );
	}
	*/
	while(scanf("%lld %lld",&n, &m) == 2)
	{
		printf("%lld\n", fact_mod(n, n-m+1));
	}
	/*
	
	for(int i=14; i<1000; i++)
	{
		//scanf("%d %d",&n, &m);
		//printf("pow: %d\n", mod(n,m,10));
		n = fact(i);
		printf("fact %5d: %5lld, %5lld\n", i, fact(i), fact_mod(i) );
	}
	*/
	return 0;
}
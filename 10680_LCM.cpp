#include "stdio.h"

long long int arr[1000], arr2[1000];

long long int GCD(long long int a, long long int b)
{
	for(;;)
	{
		b %= a;
		if(0 == b) return a;
		a %= b;
		if(0 == a) return b;
	}
}

int gcd_euclid(int a, int b)
{
	if(b==0) return a;
	if(a==b) return a;
	return gcd_euclid(b, a%b);
}

long long int LCM(long long int a, long long int b)
{
	long long int gcd = GCD(a,b);
	return gcd>0 ? a*b/gcd : 1;
}

int main()
{
	arr[0]=1;
	arr2[0]=1;
	for(long long int i=1; i<100; i++)
	{
		arr[i] = LCM(arr[i-1],i);
		arr2[i] = LCM(arr2[i-1],i);
		while(arr2[i]%10 == 0)
			arr2[i] /= 10;
		printf("LCM(%lld) = %lld, %lld\n", i, arr[i], arr2[i] );
	}
	return 0;
}
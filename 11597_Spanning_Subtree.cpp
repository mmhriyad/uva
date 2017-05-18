#include "stdio.h"

int main()
{
	int i=1, n;
	for(;;)
	{
		scanf("%d", &n);
		if(0 == n)
			return 0;
		printf("Case %d: %d\n", i++, n>>1); //n/2
	}
}
#include <stdio.h>
#include <math.h>

int MAX;

int getpos(int node, int n)
{
	int left = 2*node, right = left + 1;
	if(left < MAX && right < MAX)
	{
		if(n&1)
			getpos(left, n/2 + 1);
		else getpos(right, n/2);
	}
	else
		return node;
}

int main()
{
	int T, d, n;
	for(;;)
	{
		scanf("%d", &T);
		if(T == -1) return 0;
		while(T--)
		{
			scanf("%d %d", &d, &n);
			MAX = pow(2.0, d);
			printf("%d\n", getpos(1, n));
		}
	}
}
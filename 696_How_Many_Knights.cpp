#include <stdio.h>

#define HALF(x) ((x&1) ? (x+1)/2 : x/2)

int main()
{
	//freopen("input.txt", "r", stdin);
	int i, j, m, n, res, tmp;
	for(;;)
	{
		scanf("%d %d", &m, &n);
		i = m;
		j = n;
		if(m == 0 && n == 0)
			return 0;
		if(m > n)
		{
			tmp = m;
			m = n;
			n = tmp;
		}
		if(m == 1) res = n;
		else if(m == 2)
		{
			if(n%4 == 0)
				res = m*n/2;
			else
				res = m * (n/2 +1);
		}
		else res = HALF(m*n);
		printf("%d knights may be placed on a %d row %d column board.\n", res, i, j);
	}
}
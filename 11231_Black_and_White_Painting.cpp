#include <stdio.h>

int main()
{
	int m, n, c, i, j, res, res2, k;
	for(;;)
	{
		scanf("%d %d %d", &m, &n, &c);
		if(m == 0 && n==0 && c==0)
			return 0;
		/*if(m > n)
		{
			int tmp = m;
			m = n;
			n = tmp;
		}*/
		res = (n-7)/2 * (m-7)/2 + (n-6)/2 * (m-7)/2;
		if((n%2 == 0) && (m%2 == 0))
			res += c;
		else if((n%2 == 1) && (m%2 == 1))
			res = res;
		else
		{
			int tmp = m;
			m = n;
			n = tmp;

			res2 = (n-7)/2 * (m-7)/2 + (n-6)/2 * (m-7)/2;
			if(res2 > res)
				res = res2;
		}
		/*printf("%d, ", res);
		res = 0;
		for(i=m, k=0; i>=8; i--, k++)
		{
			for(j=n-!(c^(k&1)); j>=8; j-=2)
			{
				res++;
			}
		}*/

		printf("%d\n", res);

	}
}
#include <stdio.h>

int main()
{
	int m, n;
	for(;;)
	{
		scanf("%d %d", &m, &n);
		if((m == 1) && (n == 1))
			return 0;

		int tmp, d, arr[1000], i = 0, j, k;
		do
		{
			d = m/n;
			if(d>0) m = m%n;
			if(m == 0) d--;
			arr[i++] = d;
			if(m>1)
			{
				tmp = m;
				m = n;
				n = tmp;
			}
			else
				arr[i] = n-1;
		}while(m>1);

		char c;
		for(j = 0; j <= i; j++)
		{
			if(j&1) c = 'L';
			else c = 'R';
			for(k=0; k<arr[j]; k++)
				printf("%c", c);
		}
		printf("\n");
	}
}
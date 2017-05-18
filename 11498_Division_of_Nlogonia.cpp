#include "stdio.h"

int main()
{
	int K, M, N, x, y, i, shift=31;
	char arr[4][4] = {"NE", "SE", "NO", "SO"};
	for(;;)
	{
		scanf("%d", &K);
		if(K==0)
			return 0;
		scanf("%d %d", &N, &M);
		for(i=0;i<K;i++)
		{
			scanf("%d %d", &x, &y);
			//printf("%d==", (((x-N)>>shift)<<1 | ((y-M)>>shift)));
			if(x==N || y==M)
				printf("divisa\n");
			//else printf("%s\n", arr[(((x-N)>>shift)<<1 + ((y-M)>>shift))]);
			
			else if((x-N)>0)
			{
				if(y-M>0)
					printf("NE\n");
				else
					printf("SE\n");
			}
			else if((x-N)<0)
			{
				if(y-M>0)
					printf("NO\n");
				else
					printf("SO\n");
			}
			
		}
	}
	return 0;
}
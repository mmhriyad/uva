#include <stdio.h>

#define MAXN 3001

bool found[MAXN];

int main()
{
	freopen("input.txt", "r", stdin);
	int n, diff, a, b, i, total;
	while(scanf("%d", &n) == 1)
	{
		total = 0;
		for(i=0; i<n; i++)
			found[i] = false;
		
		scanf("%d", &a);
		for(i=1; i<n; i++)
		{
			scanf("%d", &b);
			
			if(a > b)
				diff = (a-b);
			else
				diff = (b-a);

			if(diff < n)
			{
				if(!found[diff])
				{
					found[diff] = true;
					total++;
				}
			}
			a = b;
		}
		if(total == n-1)
			printf("Jolly\n");
		else
			printf("Not jolly\n");
	}
}
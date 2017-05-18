//accepted
#include <stdio.h>
#include <stdlib.h>

#define MAX_VAL 999999

int points[4004004][2];

int main()
{
	int a,b,i,j, mindx, mindy, m, n, min_dist, dist;

	for(;;)
	{
		scanf("%d", &m);

		if(m==0) return 0;
		int startx, starty, prevx, prevy, count;
		count = 0;

		for(i=0;i<m;i++)
		{
			scanf("%d %d", &a, &b);
				if(i == 0)
				{
					prevx = startx = a;
					prevy = starty = b;
				}
				if((startx != a && starty != b) || i==0 || i==m-1)
				{
					points[count][0] = prevx;
					points[count][1] = prevy;
					count++;

					if(i==m-1)
					{
						points[count][0] = a;
						points[count][1] = b;
						count++;
					}
					if((startx != a && starty != b))
					{
						startx = prevx;
						starty = prevy;
					}
				}
				prevx = a;
				prevy = b;
			//points[i][0] = a;
			//points[i][1] = b;
		}

		mindx = mindy = min_dist = MAX_VAL;
		

		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%d %d", &a, &b);

			for(j=0; j<count; j++)
			{
				if(j == 0)
				{
					prevx = startx = points[j][0];
					prevy = starty = points[j][1];
				}
				if((startx != points[j][0] && starty != points[j][1]) || j==0 || j==m-1)
				{
					dist = abs( prevx - a ) + abs( prevy - b );
					if(dist < min_dist)
						min_dist = dist;

					if(j==m-1)
					{
						dist = abs( points[j][0] - a ) + abs( points[j][1] - b );
						if(dist < min_dist)
							min_dist = dist;
					}
					if((startx != points[j][0] && starty != points[j][1]))
					{
						startx = prevx;
						starty = prevy;
					}
				}
				prevx = points[j][0];
				prevy = points[j][1];
				
			}
		}

		printf("%d\n", min_dist);
	}

	return 0;
}
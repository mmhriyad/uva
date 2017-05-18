#include <stdio.h>
#include <string.h>

#define MAXS 1025

int arr[MAXS][MAXS];

int main()
{	
	//freopen("input.txt", "r", stdin);
	int d=0, n, x, y, i, j, k, T, cnt;
	int max_des = 0, posx, posy, sx, sy, ex, ey;
	scanf("%d", &T);
	while(T--)
	{
		memset(arr, 0, sizeof(arr));
		scanf("%d", &d);
		scanf("%d", &n);
		max_des = posx = posy = 0;

		for(k=0; k<n; k++)
		{
			scanf("%d %d %d", &x, &y, &cnt);
			sx = x-d;
			sy = y-d;
			ex = x+d;
			ey = y+d;
			if(sx<0) sx = 0;
			if(sy<0) sy = 0;
			if(ex >= MAXS) ex = MAXS-1;
			if(ey >= MAXS) ey = MAXS-1;

			for(i=sx; i<=ex; i++)
			{
				for(j=sy; j<=ey; j++)
				{
					arr[i][j] += cnt;
					if(arr[i][j] > max_des)
					{
						max_des = arr[i][j];
						posx = i;
						posy = j;
					}
					
					else if(arr[i][j] == max_des)
					{
						if(i<posx)
						{
							posx = i;
							posy = j;
						}
						else if(i==posx && j<posy)
							posy = j;

					}
					
				}
			}
		}
		printf("%d %d %d\n", posx, posy, max_des);

	}
}
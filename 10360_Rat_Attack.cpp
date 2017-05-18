#include <stdio.h>

#define MAXS 1025

int arr[MAXS][MAXS];

int getcount(int x, int y, int d)
{
	int cnt = 0, startx = x, starty = y;
	if(x==974 && y == 974)
		x = x;
	if(startx-d>0)
		startx-=d;
	if(starty-d>0)
		starty-=d;
	
	for(int i=startx; i<=(x+d); i++)
		for(int j=starty; j<=(y+d); j++)
			cnt += arr[i][j];
	return cnt;
}

int main()
{	
//	freopen("input.txt", "r", stdin);
	int d=0, n, x, y, i, j, k, T, cnt;
	int max_des = 0, posx=0, posy=0;
	int minx=0, maxx=0, miny=0, maxy=0;
	scanf("%d", &T);
	while(T--)
	{
		maxx+=d;
		if(maxx>=MAXS) maxx = MAXS-1;
		maxy+=d;
		if(maxy>=MAXS) maxy = MAXS-1;
		for(i=minx; i<=maxx; i++)
			for(j=miny; j<=maxy; j++)
				arr[i][j] = 0;
		scanf("%d", &d);
		scanf("%d", &n);
		minx = miny = MAXS;
		maxx = maxy = 0;
		for(i=0; i<n; i++)
		{
			scanf("%d %d %d", &x, &y, &cnt);
			arr[x][y] = cnt;
			if(x<minx) minx = x;
			if(x>maxx) maxx = x;
			if(y<miny) miny = y;
			if(y>maxy) maxy = y;
		}
		if(minx-d >= 0)
			minx -= d;
		else minx = 0;
		if(miny-d >= 0)
			miny -= d;
		else miny = 0;

		if(maxx > MAXS-d)
			maxx = MAXS-d;
		if(maxy > MAXS-d)
			maxy = MAXS-d;

		max_des = posx = posy = 0;
		for(i=minx; i<maxx; i++)
		{
			for(j=miny; j<maxy; j++)
			{
				cnt = getcount(i, j, d);
				if(max_des < cnt)
				{
					max_des = cnt;
					posx = i;
					posy = j;
				}
			}
		}
		printf("%d %d %d\n", posx, posy, max_des);

	}
}
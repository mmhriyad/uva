/*
824_Coast_Tracker.cpp
Author : Md. Mahbubul Huq (Riyad)
*/
#include <stdio.h>

#define LAND 1
#define WATER 0

int main()
{
	
	int arr[3][3];
	int posx, posy, a, b, c, i, curdir, nextdir;
	while(1)
	{
		scanf("%d", &posx);
		if(posx == -1)
			return 0;
		scanf("%d %d", &posy, &curdir);
		for(i=0; i<8; i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			arr[1-(b-posy)][1+(a-posx)] = c;
		}
		if(curdir>1)
			nextdir = curdir - 2;
		else
			nextdir = 8 + curdir - 2;
		for(i=0; i<8; i++)
		{
			if(nextdir == 0 && arr[0][1] == LAND)
				break;
			if(nextdir == 1 && arr[0][0] == LAND)
				break;
			if(nextdir == 2 && arr[1][0] == LAND)
				break;
			if(nextdir == 3 && arr[2][0] == LAND)
				break;
			if(nextdir == 4 && arr[2][1] == LAND)
				break;
			if(nextdir == 5 && arr[2][2] == LAND)
				break;
			if(nextdir == 6 && arr[1][2] == LAND)
				break;
			if(nextdir == 7 && arr[0][2] == LAND)
				break;
			nextdir = (nextdir + 1) % 8;
		}
		printf("%d\n", nextdir);
	}

}

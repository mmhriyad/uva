#include <stdio.h>
/*
Passed means current height > well height 
Failed means current height < 0 
*/
int main()
{
	int H, day;
	double D, F, U, ff, dist = 0;
	//freopen("input.txt", "r", stdin);
	for(;;)
	{
		scanf("%d %lf %lf %lf", &H, &U, &D, &F);
		
		if(H == 0)
			return 0;

		ff = U*F/100.0;
		dist = 0;
		day = 0;
		while(1)
		{
			day++;
			dist += U;
			if(dist > H) break;
			dist -= D;
			if(dist <= 0)
			{
				if(dist == 0)
					day++;
				break;
			}
			U -= ff;
			if(U < 0) U = 0;
		}
		if(dist < H)
			printf("failure on day %d\n", day);
		else
			printf("success on day %d\n", day);
	}

}
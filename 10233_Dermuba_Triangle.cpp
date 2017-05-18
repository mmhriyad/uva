/*
if length of a equilatteral = 1
then, height = sqrt(3)/2

then,
	one unit in vertical = sqrt(3)/2/3
	one unit in horizontal = 1/2

*/

#include "stdio.h"
#include "math.h"


double xfactor = 1.0/2.0,  yfactor = sqrt(3.0)/6.0;


void getXY(long long int number, long long int i, long double *x, long double *y)
{
	long long int total_num = (i)*2-1; //i start from 1;
	long long int min, max, mid, mid_y;
	min = (i*i);
	max = (i+1)*(i+1) - 1;
	mid = (min+max)/2;

	if(i%2) //odd
	{
		mid_y = 3*i + 1;
	}
	else mid_y = 3*i + 2;

	*x = number - mid;

	if(number%2) //odd
	{
			if(i%2) *y = mid_y + 1;
			else *y = mid_y - 1;
	}
	else *y = mid_y;

	//*x *= xfactor;
	//*y *= yfactor;
}

int main()
{
	long double x1, y1, x2, y2, distX, distY;
	long long int i1, i2;
	long long int a, b;
	

	while(scanf("%lld %lld", &a, &b) == 2)
	{
	

	i1 = (int)(sqrt((double)a)); //0 based index;
	i2 = (int)(sqrt((double)b));

	getXY(a, i1, &x1, &y1);
	getXY(b, i2, &x2, &y2);

	distX = x1 - x2;
	//if(distX<0) distX = -distX;

	distY = y1 - y2;
	//if(distY<0) distY = -distY;


	printf("%.3lf\n", hypot(distX*xfactor, distY*yfactor));
	}
	return 0;
}
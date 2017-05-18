/*
#include <stdio.h>

#define GETD(x1,y1,x2,y2,x3,y3,x4,y4) ( ((x1-x2)*(y3-y4)) - ((y1-y2)*(x3-x4)) )

#define GETX(x1,y1,x2,y2,x3,y3,x4,y4) ( ((x1*y2 - x2*y1)*(x3-x4)) - ((x1-x2)*(x3*y4-x4*y3)) )
#define GETY(x1,y1,x2,y2,x3,y3,x4,y4) ( ((x1*y2 - x2*y1)*(y3-y4)) - ((y1-y2)*(x3*y4-x4*y3)) )

int main()
{
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int N, x1, y1, x2, y2, x3, y3, x4, y4, d, i;
	double px, py;
	scanf("%d", &N);
	printf("INTERSECTING LINES OUTPUT\n");
	for (i = 0; i < N; ++i)
	{
		scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
		d = GETD(x1, y1, x2, y2, x3, y3, x4, y4);
		if (d == 0) //parallel lines/coincident lines
		{
			if (x1 == x2 && x3 == x4)
				printf("LINE\n");
			else if ((x1 == x2 && x3 != x4) || (x1 != x2 && x3 == x4))
				printf("NONE\n");
			else
			{
				int c1, c2, m;
				m = (y1 - y2) / (x1 - x2);
				c1 = m*x1 - y1;
				c2 = m*x3 - y3;
				if (c1 == c2)
					printf("LINE\n");
				else
					printf("NONE\n");
			}
		}
		else
		{
			px = double(GETX(x1, y1, x2, y2, x3, y3, x4, y4)) / d;
			py = double(GETY(x1, y1, x2, y2, x3, y3, x4, y4)) / d;

			printf("POINT %.2lf %.2lf\n", px, py);
		}
	}
	printf("END OF OUTPUT\n");
}
*/

#include<stdio.h>


int main()
{
	
	int n, x_1, x_2, x_3, x_4, y_1, y_2, y_3, y_4;
	double d, d1, d2, t1, t2, x, y;

	scanf("%d", &n);

	printf("INTERSECTING LINES OUTPUT\n");
	while (n>0)
	{
		scanf("%d %d %d %d %d %d %d %d", &x_1, &y_1, &x_2, &y_2, &x_3, &y_3, &x_4, &y_4);
		d = (double)((x_1 - x_2)*(y_3 - y_4)) - ((y_1 - y_2)*(x_3 - x_4));
		d1 = (double)((x_3 - x_4)*(y_3 - y_1)) - ((y_3 - y_4)*(x_3 - x_1));
		d2 = (double)(-((x_3 - x_1)*(y_1 - y_2)) + ((y_3 - y_1)*(x_1 - x_2)));


		if ((int)d == 0 && (int)d1 == 0 && (int)d2 == 0)
		{
			printf("LINE\n");
		}
		else if ((int)d == 0)
		{
			printf("NONE\n");
		}
		else
		{
			t1 = d1 / d;
			t2 = d2 / d;
			x = x_1 + t1*(x_2 - x_1);
			y = y_1 + t1*(y_2 - y_1);
			printf("POINT %.2lf %.2lf\n", x, y);
		}
		n--;

	}
	printf("END OF OUTPUT\n");
	return 0;
}
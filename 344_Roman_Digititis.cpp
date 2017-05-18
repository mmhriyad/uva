#include <stdio.h>

int count[101][5];

void init()
{
	int i, a, j;
	for(i=1;i<=100;i++)
	{
		a = i;
		while(a>0)
		{
			if(a == 1)
			{
				count[i][0]++;
				a = 0;
			}
			else if(a>1 && a<4)
			{
				count[i][0] += a;
				a = 0;
			}
			else if(a == 4)
			{
				count[i][0]++;
				count[i][1]++;
				a = 0;
			}
			else if(a == 5)
			{
				count[i][1]++;
				a = 0;
			}
			else if(a>5 && a<9)
			{
				count[i][0] += a-5;
				count[i][1]++;
				a = 0;
			}
			else if(a == 9)
			{
				count[i][0]++;
				count[i][2]++;
				a = 0;
			}
			else if(a == 10)
			{
				count[i][2]++;
				a = 0;
			}
			else if(a>10 && a<40)
			{
				count[i][2] += a/10;
				a %= 10;
			}
			else if(a == 40)
			{
				count[i][2]++;
				count[i][3]++;
				a = 0;
			}
			else if(a>40 && a<50)
			{
				count[i][2]++;
				count[i][3]++;
				a -= 40;
			}
			else if(a == 50)
			{
				count[i][3]++;
				a = 0;
			}
			else if(a>50 && a<90)
			{
				count[i][3]++;
				a -= 50;
			}
			else if(a == 90)
			{
				count[i][2]++;
				count[i][4]++;
				a = 0;
			}
			else if(a>90 && a<100)
			{
				count[i][2]++;
				count[i][4]++;
				a -= 90;
			}
			else if(a == 100)
			{
				count[i][4]++;
				a = 0;
			}
		}

		for(j=0; j<5; j++)
			count[i][j] += count[i-1][j];
		
	}
}

int main()
{
	init();
	int a, caseno = 1;
	while(scanf("%d", &a) == 1 && a)
	{
		printf("%d: %d i, %d v, %d x, %d l, %d c\n", a, count[a][0], count[a][1], count[a][2], count[a][3], count[a][4]);
	}
}
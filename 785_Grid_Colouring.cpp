#include <stdio.h>
#include <string.h>

#define MAXL 40
#define MAXC 100
#define MAXDIR 4 //8

#define GETMAX(x, y) (x>y ? x : y)

int T, m, n;

char arr[MAXL][MAXC];
const char blank = ' ', endc = '_', wall = 'X';

typedef struct
{
	int x, y;
	char fill;
}point;
point p[MAXL*MAXC];

//int dir[MAXDIR][2] = {{-1,-1}, {-1,0}, {-1,1},
//{0,-1}, {0, 1},
//{1,-1}, {1, 0}, {1,1}};

int dir[MAXDIR][2] = {{-1,0}, {0,-1}, {0,1}, {1,0}};



void fill(int x, int y, char fcolor)
{
	int i, j, a, b;
	arr[x][y] = fcolor;
	n = strlen(arr[x]);
	for(i=0; i<MAXDIR; i++)
	{
		a = x + dir[i][0];
		b = y + dir[i][1];
		if((a<m && a>=0) && (b<n && b>=0) && arr[a][b] == blank)
			fill(a, b, fcolor);
	}
}

void print()
{
	int i;
	for(i=0; i<=m; i++)
		printf("%s", arr[i]);
}

int main()
{
	freopen("input.txt", "r", stdin);
	int i, j, npoints = 0;
	char ch;
	bool ret = false;

	while(!ret)
	{
		i = 0;
		n = 0;
		j = 0;
		npoints = 0;
		memset(arr, 0x00, sizeof(arr));
		for(;;)
		{
			ch = getchar();
			arr[i][j] = ch;
			if(ch == EOF)
			{
				arr[i][j] = '\n';
				ret = true;
				break;
			}
			else if(ch == '\n')
			{
				if(arr[i][j-1] == endc)
					break;
				i++;
				m = i;
				j = -1;
			}
			else if((ch !=  blank) && (ch != wall) && (ch != endc))
			{
				p[npoints].x = i;
				p[npoints].y = j;
				p[npoints].fill = ch;
				npoints++;
			}

			j++;
		}

		for(i=0; i<npoints; i++)
			fill(p[i].x, p[i].y, p[i].fill);
		print();
	}
}
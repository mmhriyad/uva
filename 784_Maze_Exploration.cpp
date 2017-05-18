#include <stdio.h>
#include <string.h>

#define MAXL 40
#define MAXC 100
#define MAXDIR 4 //8

#define GETMAX(x, y) (x>y ? x : y)

int T, m, n;

char arr[MAXL][MAXC];
const char blank = ' ', endc = '_', wall = 'X', point = '*', paint = '#';

//int dir[MAXDIR][2] = {{-1,-1}, {-1,0}, {-1,1},
//{0,-1}, {0, 1},
//{1,-1}, {1, 0}, {1,1}};
int dir[MAXDIR][2] = {{-1,0}, {0,-1}, {0,1}, {1,0}};

void fill(int x, int y)
{
	int i, j, a, b;
	arr[x][y] = paint;
	n = strlen(arr[x]);
	for(i=0; i<MAXDIR; i++)
	{
		a = x + dir[i][0];
		b = y + dir[i][1];
		if((a<m && a>=0) && (b<n && b>=0) && arr[a][b] == blank)
			fill(a, b);
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
	int i, x, y, j;
	char ch;
	scanf("%d", &T);
	ch = getchar();
	while(T--)
	{
		i = 0;
		n = 0;
		j = 0;
		x = y = -1;
		memset(arr, 0x00, sizeof(arr));
		for(;;)
		{
			//scanf("%s", &arr[i]);
			//gets(arr[i]);
			//cin.getline(arr[i], MAXC);
			//scanf ("%[^\n]%*c", &arr[i]);
			//fgets (arr[i], MAXC, stdin);
			
			ch = getchar();
			arr[i][j] = ch;
			if(ch == EOF)
			{
				arr[i][j] = '\n';
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
			else if(ch == point)
			{
				x = i;
				y = j;
			}

			j++;

		}

		fill(x, y);
		print();
	}
}
#include <stdio.h>

#define MAXN 50
#define TRAP 'T'
#define FLOOR '.'
#define GOLD 'G'

char arr[MAXN][MAXN + 1];
int W, H, count;

void fill(int x, int y)
{
	int i, a, b;
	int dir[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
	if (arr[x][y] == GOLD)
		count++;
 	arr[x][y] = '#';
	char ch;
	for (i = 0; i < 4; i++)
	{
		a = x + dir[i][0];
		b = y + dir[i][1];
		if (a >= 0 && a < H && b >= 0 && b < W)
		{
			ch = arr[a][b];
			if (arr[a][b] == TRAP)
			{
				return;
			}
		}
	}
	for (i = 0; i < 4; i++)
	{
		a = x + dir[i][0];
		b = y + dir[i][1];
		if (a >= 0 && a < H && b >= 0 && b < W)
		{
			ch = arr[a][b];
			if (arr[a][b] == FLOOR || arr[a][b] == GOLD)
			{
				fill(a, b);
			}
		}
	}
	
}


int main()
{
	//freopen("inp.txt", "r", stdin);
	W = H = 0;
	int i, j, px, py;
	while (scanf("%d %d", &W, &H) == 2)
	{
		gets(arr[0]);
		px = py = -1;
		for (i = 0; i < H; i++)
		{
			gets(arr[i]);
			if (px < 0)
			{
				j = 0;
				while (arr[i][j])
				{
					if (arr[i][j] == 'P')
					{
						px = i;
						py = j;
						break;
					}
					j++;
				} //while (arr[i][j])
			} //if (px < 0)
		} //for
		count = 0;
		fill(px, py);
		printf("%d\n", count);
	}
	return 0;
}
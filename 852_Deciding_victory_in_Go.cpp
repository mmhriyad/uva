#include <stdio.h>
#include <string.h>

int black = 0, white = 0;
const char cb = 'X', cw = 'O', cempty = '.';

#define BSIZE 9

char arr[BSIZE][BSIZE+1];
bool visited[BSIZE][BSIZE];
int T;

int dir[4][2] = {{-1,0}, {1,0}, {0, -1}, {0, 1}};

bool canfill(int x, int y, char ch)
{
	//printf("x=%d, y=%d, xh=%c, arr[x][y]=%c\n", x, y, ch, arr[x][y]);
	int i, a, b;
	
	if(arr[x][y] == cempty)
		visited[x][y] = true;

	for(i=0; i<4; i++)
	{
		a = x + dir[i][0];
		b = y + dir[i][1];
		if((a>=0 && a<BSIZE) && (b>=0 && b<BSIZE) && !visited[a][b])
		{
			if(arr[a][b] == cempty)
			{
				if(!canfill(a, b, ch))
					return false;
			}
			else if(arr[a][b] != ch)
				return false;
		}
	}
	return true;
}

void fill(int x, int y, char ch)
{
	int i, a, b;
	
	if(arr[x][y] == cempty)
		arr[x][y] = ch;

	for(i=0; i<4; i++)
	{
		a = x + dir[i][0];
		b = y + dir[i][1];
		if((a>=0 && a<BSIZE) && (b>=0 && b<BSIZE) && arr[a][b] == cempty)
			fill(a, b, ch);
	}
}

void remove(int x, int y)
{
	int i, a, b;
	
	if(arr[x][y] == cempty)
		arr[x][y] = '-';

	for(i=0; i<4; i++)
	{
		a = x + dir[i][0];
		b = y + dir[i][1];
		if((a>=0 && a<BSIZE) && (b>=0 && b<BSIZE) && arr[a][b] == cempty)
			remove(a, b);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	int i, j, l, m;
	while(T--)
	{
		black = white = 0;
		memset(visited, false, sizeof(visited));
		for(i=0; i<BSIZE; i++)
			scanf("%s", &arr[i]);
		for(i=0; i<BSIZE; i++)
		{
			for(j=0; j<BSIZE; j++)
			{
				if((arr[i][j] == cempty))
				{
					for(l=0; l<4; l++)
					{
						int a = i + dir[l][0];
						int b = j + dir[l][1];
						if((a>=0 && a<BSIZE) && (b>=0 && b<BSIZE) && (arr[a][b] == cb || arr[a][b] == cw))
						{
							if(canfill(i, j, arr[a][b]))
							{
								fill(i, j, arr[a][b]);
								break;
							}
							else
								remove(i, j);
						}
					}
				}
			}
		}

		for(i=0; i<BSIZE; i++)
		{
			for(j=0; j<BSIZE; j++)
			{
				if(arr[i][j] == cb)
					black++;
				else if(arr[i][j] == cw)
					white++;
			}
		}

		printf("Black %d White %d\n", black, white);
	}
	return 0;
}
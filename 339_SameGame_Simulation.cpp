/*
339_SameGame_Simulation.cpp
Author : Md. Mahbubul Huq (Riyad)
*/
#include <stdio.h>


#define MAX_X 11
#define MAX_Y 41

#define BLANK -1

int arr[MAX_X][MAX_Y];
int sx, sy, moved_balls;
int MAXX, MAXY, MAX_BALLS;

int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

bool is_blank_column(int y)
{
	int i;
	for (i = 0; i < MAXX; i++)
		if (arr[i][y] != BLANK)
			break;
	if (i == MAXX)
		return true;
	return false;
}

void drop_down()
{
	int i, j, k, sx;

	for (j = 0; j < MAXY; j++)
	{
		i = 0;
		while (i < MAXX)
		{
			for (; i < MAXX-1; i++)
				if (arr[i][j] == BLANK)
					break;
			sx = i;
			for (i = sx + 1; i < MAXX; i++)
				if (arr[i][j] != BLANK)
					break;
			for (k = sx; i < MAXX && k < MAXX-1; i++, k++)
			{
				if (arr[i][j] == BLANK)
					break;
				arr[k][j] = arr[i][j];
				arr[i][j] = BLANK;
			}
			if (k < MAXX-1 && i < MAXX)
				i = k;
		}
	}
}

void move_left(int y)
{
	int i, j, k;
	for (k = y + 1; k < MAXY; k++)
		if (!is_blank_column(k))
			break;

	for (j = y; j < MAXY-1, k < MAXY; j++, k++)
	{
		for (i = 0; i < MAXX; i++)
		{
			arr[i][j] = arr[i][k];
			arr[i][k] = BLANK;
		}
	}
}

int count;

void delete_same(int x, int y, int c)
{
	int i, nx, ny;
	arr[x][y] = BLANK;
	count++;
	for (i = 0; i < 4; i++)
	{
		nx = x + dir[i][0];
		ny = y + dir[i][1];
		if ((nx >= 0 && nx < MAXX && ny >= 0 && ny < MAXY) && arr[nx][ny] == c)
			delete_same(nx, ny, c);
	}
}

void print_arr()
{
	int i, j;
	
	for (i = MAXX - 1; i >= 0; i--)
	{
		printf("   ");
		for (j = 0; j < MAXY; j++)
		{
			if (arr[i][j] >= 0)
				printf(" %d", arr[i][j]);
			else printf("  ");
		}
		printf("\n");
	}
}

int main()
{
	int cn = 0, i, j;
	int colorc;
	while (scanf("%d %d", &MAXX, &MAXY) == 2)
	{
		if (MAXX == 0 && MAXY == 0)
			break;
		MAX_BALLS = MAXX * MAXY;
		for (i = 0; i < MAXX; i++)
		{
			for (j = 0; j < MAXY; j++)
				scanf("%d", &arr[i][j]);
		}
		if (cn > 0)
			printf("\n");

		printf("Grid %d.\n", ++cn);
		
		moved_balls = 0;
		while (1)
		{
			scanf("%d %d", &sx, &sy);
			if (sx == 0 && sy == 0)
				break;
			if ((sx > MAXX) || (sy > MAXY))
				continue;

			sx--;
			sy--;
			colorc = arr[sx][sy];
			if (colorc < 0)
				continue;
			count = 0;
			delete_same(sx, sy, colorc);
			
			if (count < 2)
			{
				arr[sx][sy] = colorc;
				continue;
			}
			
			moved_balls += count;
			
			if (moved_balls < MAX_BALLS)
			{

				drop_down();

				for (j = 0; j < MAXY - 1; j++)
				{
					if (is_blank_column(j))
					{
						move_left(j);
					}
				}
			}
		}//while
		if (moved_balls == MAX_BALLS)
			printf("    Game Won\n");
		else
			print_arr();
	}
	return 0;
}

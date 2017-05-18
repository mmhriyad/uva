/*
758_The_Same_Game.cpp
Author : Md. Mahbubul Huq (Riyad)
*/
#include <stdio.h>
#include <string.h>

#define MAXX 10
#define MAXY 15
#define MAX_BALLS 150
#define BLANK '-'

char arr[MAXX][MAXY+10], temp[MAXX][MAXY+10];
int sx, sy, maxp, total_points, current_points, moved_balls;

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
		while (i < MAXX - 1)
		{
			for (; i < MAXX - 1; i++)
				if (arr[i][j] == BLANK)
					break;
			sx = i;
			for (i = sx + 1; i < MAXX; i++)
				if (arr[i][j] != BLANK)
					break;
			for (k = sx; i < MAXX && k < MAXX; i++, k++)
			{
				if (arr[i][j] == BLANK)
					break;
				arr[k][j] = arr[i][j];
				arr[i][j] = BLANK;
			}
			if (k < MAXX && i < MAXX)
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
void get_count(int x, int y, char c)
{
	int i, nx, ny;
	temp[x][y] = BLANK;
	count++;
	for (i = 0; i < 4; i++)
	{
		nx = x + dir[i][0];
		ny = y + dir[i][1];
		if ((nx >= 0 && nx < MAXX && ny >= 0 && ny < MAXY) && temp[nx][ny] == c)
			get_count(nx, ny, c);
	}
}

void delete_same(int x, int y, char c)
{
	int i, nx, ny;
	arr[x][y] = BLANK;

	for (i = 0; i < 4; i++)
	{
		nx = x + dir[i][0];
		ny = y + dir[i][1];
		if ((nx >= 0 && nx < MAXX && ny >= 0 && ny < MAXY) && arr[nx][ny] == c)
			delete_same(nx, ny, c);
	}
}

void print_arr(char *str)
{
	int i;
	printf("=============== %s ==================\n", str);
	for (i = MAXX-1; i >= 0; i--)
		puts(arr[i]);
	printf("==============================================\n");
}

int main()
{
	freopen("inp.txt", "r", stdin);
	int T, cn, i, j, move;
	char colorc;
	scanf("%d", &T);
	for (cn = 1; cn <= T; cn++)
	{
		i = MAXX - 1;
		while (gets(arr[i]))
		{
			if (arr[i][0])
				break;
		}
		i--;
		for (; i >= 0; i--)
		{
			gets(arr[i]);
		}

		printf("Game %d:\n\n", cn);
		
		move = 0;
		total_points = moved_balls = 0;
		while (1)
		{
			memcpy(&temp, &arr, sizeof(arr));
			maxp = 1;
			move++;
			for (j = 0; j < MAXY; j++)
			{
				
				for (i = 0; i < MAXX; i++)
				{
					if (temp[i][j] != BLANK)
					{
						count = 0;
						get_count(i, j, temp[i][j]);
						if (count > maxp)
						{
							maxp = count;
							sx = i;
							sy = j;
						}
					}
				}//for j
			}//for i
			if (maxp == 1)
				break;
			colorc = arr[sx][sy];
			delete_same(sx, sy, colorc);
			current_points = ((maxp - 2)*(maxp - 2));
			total_points += current_points;
			moved_balls += maxp;
			
			printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n", move, sx + 1, sy + 1, maxp, colorc, current_points);
			
			if (moved_balls < MAX_BALLS)
			{
				//print_arr("before down");
				drop_down();
				//print_arr("after down");
				for (j = 0; j < MAXY - 1; j++)
				{
					if (is_blank_column(j))
					{
						move_left(j);
					}
				}
				//print_arr("after left");
			}
		}//while
		if (moved_balls == MAX_BALLS)
			total_points += 1000;

		printf("Final score: %d, with %d balls remaining.\n", total_points, (MAX_BALLS - moved_balls));
		
		if (cn < T)
			printf("\n");
	}
	return 0;
}
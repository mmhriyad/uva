#include <stdio.h>
#include <string.h>

#define BSIZE 8

#define IN_BOARD(x,y) ((x>=0 && x<BSIZE) && (y>=0 && y<BSIZE))

#define BLANK '.'
#define VISITED '-'
#define NOT_SAFE 'x'

char board[BSIZE][BSIZE+1];

char bishop[2] = {'b', 'B'};
char pawn[2] = {'p', 'P'};
char boat[2] = {'r', 'R'};
char king[2] = {'k', 'K'};
char queen[2] = {'q', 'Q'};
char knight[2] = {'n', 'N'};

int ns_count = 0, nb_count = 0;

#define CHECK_BOARD(x,y)\
		if(board[x][y] == BLANK)\
		{\
			board[x][y] = VISITED;\
			ns_count++;\
		}\
		else if(board[x][y] == VISITED)\
		{\
			board[x][y] = NOT_SAFE;\
		}\

#define CHECK_BOARD_L(x,y) {\
		CHECK_BOARD(x,y)\
		else if(board[x][y] == NOT_SAFE)\
			continue;\
		else\
			break;\
}\

void move_bishop(int x, int y)
{
	int i=x, j=y;
	while(1)
	{
		x--;
		y--;
		if(!IN_BOARD(x,y))
			break;
		CHECK_BOARD_L(x,y);
	}
	x = i;
	y = j;
	while(IN_BOARD(x,y))
	{
		x--;
		y++;
		if(!IN_BOARD(x,y))
			break;
		CHECK_BOARD_L(x,y);
	}
	x = i;
	y = j;
	while(IN_BOARD(x,y))
	{
		x++;
		y++;
		if(!IN_BOARD(x,y))
			break;
		CHECK_BOARD_L(x,y);
	}
	x = i;
	y = j;
	while(IN_BOARD(x,y))
	{
		x++;
		y--;
		if(!IN_BOARD(x,y))
			break;
		CHECK_BOARD_L(x,y);
	}
}

void move_pawn(int x, int y)
{
	if(board[x][y] == pawn[0]) //black will ++
	{
		if(IN_BOARD(x+1,y-1))
			CHECK_BOARD(x+1, y-1);
		if(IN_BOARD(x+1,y+1))
			CHECK_BOARD(x+1, y+1);
	}
	else if(board[x][y] == pawn[1]) //white will --
	{
		if(IN_BOARD(x-1,y-1))
			CHECK_BOARD(x-1, y-1);
		if(IN_BOARD(x-1,y+1))
			CHECK_BOARD(x-1, y+1);
	}
}

void move_knight(int x, int y)
{
	if(IN_BOARD(x+2,y+1))
		CHECK_BOARD(x+2, y+1);
	if(IN_BOARD(x-2,y+1))
		CHECK_BOARD(x-2, y+1);
	if(IN_BOARD(x+2,y-1))
		CHECK_BOARD(x+2, y-1);
	if(IN_BOARD(x-2,y-1))
		CHECK_BOARD(x-2, y-1);

	if(IN_BOARD(x+1,y+2))
		CHECK_BOARD(x+1, y+2);
	if(IN_BOARD(x-1,y+2))
		CHECK_BOARD(x-1, y+2);
	if(IN_BOARD(x+1,y-2))
		CHECK_BOARD(x+1, y-2);
	if(IN_BOARD(x-1,y-2))
		CHECK_BOARD(x-1, y-2);
}

void move_boat(int x, int y)
{
	int i=x, j=y;
	x;
	while(IN_BOARD(x,y))
	{
		x--;
		if(!IN_BOARD(x,y))
			break;
		CHECK_BOARD_L(x,y);
	}
	x = i;
	y = j;
	while(IN_BOARD(x,y))
	{
		x++;
		if(!IN_BOARD(x,y))
			break;
		CHECK_BOARD_L(x,y);
	}
	x = i;
	y = j;
	while(IN_BOARD(x,y))
	{
		y++;
		if(!IN_BOARD(x,y))
			break;
		CHECK_BOARD_L(x,y);
	}
	x = i;
	y = j;
	while(IN_BOARD(x,y))
	{
		y--;
		if(!IN_BOARD(x,y))
			break;
		CHECK_BOARD_L(x,y);
	}
}

void move_king(int x, int y)
{
	if(IN_BOARD(x,y-1))
		CHECK_BOARD(x, y-1);
	if(IN_BOARD(x,y+1))
		CHECK_BOARD(x, y+1);
	if(IN_BOARD(x+1,y))
		CHECK_BOARD(x+1, y);
	if(IN_BOARD(x-1,y))
		CHECK_BOARD(x-1, y);
	if(IN_BOARD(x+1,y-1))
		CHECK_BOARD(x+1, y-1);
	if(IN_BOARD(x+1,y+1))
		CHECK_BOARD(x+1, y+1);
	if(IN_BOARD(x-1,y-1))
		CHECK_BOARD(x-1, y-1);
	if(IN_BOARD(x-1,y+1))
		CHECK_BOARD(x-1, y+1);
}

void move_queen(int x, int y)
{
	move_bishop(x,y);
	move_boat(x,y);
}

typedef void (*func_move)(int, int);

typedef struct
{
	char c, cb;
	func_move f_move;
}st;

st s[6] = {
	{ 'r', 'R', move_boat },

	{ 'b', 'B', move_bishop },

	{ 'n', 'N', move_knight },

	{ 'k', 'K', move_king },

	{ 'q', 'Q', move_queen },

	{ 'p', 'P', move_pawn }
};

int main()
{
	//freopen("input.txt", "r", stdin);
	char inp[100];
	int len, i, j, k, c, l;
	while(scanf("%s", inp) == 1 && inp)
	{
		//memset(board, BLANK, sizeof(board));
		i = j = k = 0;
		len = strlen(inp);
		while(k<len)
		{
			if(inp[k] == '/')
			{
				board[i][j++] = 0x00;
				j=0;
				i++;
			}
			else
			{
				c = inp[k] - '0';
				if(c>=0 && c<=9)
				{
					while(c)
					{
						board[i][j++] = BLANK;
						c--;
					}
				}
				else
				{
					board[i][j++] = inp[k];
				}
			}
			k++;
		}

		ns_count = 0;
		nb_count = 0;
		for(i=0; i<BSIZE; i++)
		{
			for(j=0; j<BSIZE; j++)
			{
				if(board[i][j] != BLANK && board[i][j] != VISITED && board[i][j] != NOT_SAFE)
				{
					for(k=0; k<6; k++)
					{
						if(board[i][j] == s[k].c || board[i][j] == s[k].cb)
						{
							s[k].f_move(i, j);
							nb_count++;
							break;
						}
					}
				}
			}
		}

		printf("%d\n", (64 - ns_count - nb_count));

	}

	return 0;
}
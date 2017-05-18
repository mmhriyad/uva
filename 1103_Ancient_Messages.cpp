#include <stdio.h>

#define FILLED '#'
#define LINE '1'
#define BLANK '0'
#define MAXH 200
#define MAXW 50
#define TOTAL_SYMBOL 6

int W, H, hole_count;

char arr_inp[MAXH][MAXW + 1], arr_main[MAXH][MAXW * 4 + 1];

int found[TOTAL_SYMBOL];
const int holes[TOTAL_SYMBOL] = { 1, 5, 3, 2, 4, 0};
const char sym[TOTAL_SYMBOL] = { 'A', 'D', 'J', 'K', 'S', 'W' };
const char arr_decode[16][5] = { "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111" };

typedef struct
{
	int x, y;
}point_t;

point_t point_s, point_stack[MAXH*MAXW * 4], point_stack_line[MAXH*MAXW * 4];

bool traversed[MAXH][MAXW * 4];

int stack_top = 0, stack_top_line = 0;

void stack_push(int x, int y)
{
	if (!traversed[x][y])
	{
		point_stack[stack_top].x = x;
		point_stack[stack_top].y = y;
		traversed[x][y] = true;
		++stack_top;
	}
}

void stack_push_line(int x, int y)
{
	if (!traversed[x][y])
	{
		point_stack_line[stack_top_line].x = x;
		point_stack_line[stack_top_line].y = y;
		traversed[x][y] = true;
		++stack_top_line;
	}
}

void stack_pop(int *x, int *y)
{
	if (stack_top > 0)
	{
		--stack_top;
		*x = point_stack[stack_top].x;
		*y = point_stack[stack_top].y;
	}
}

void stack_pop_line(int *x, int *y)
{
	if (stack_top_line > 0)
	{
		--stack_top_line;
		*x = point_stack_line[stack_top_line].x;
		*y = point_stack_line[stack_top_line].y;
	}
}

bool stack_is_empty()
{
	return stack_top == 0;
}

bool stack_is_empty_line()
{
	return stack_top_line == 0;
}

void stack_init()
{
	stack_top = 0;
}

void stack_init_line()
{
	stack_top_line = 0;
}


void fill_hole(int x, int y)
{
	int i, a, b;
	int dir[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
	stack_init();
	stack_push(x, y);
	while (!stack_is_empty())
	{
		stack_pop(&x, &y);
		arr_main[x][y] = FILLED;
		for (i = 0; i < 4; i++)
		{
			a = x + dir[i][0];
			b = y + dir[i][1];
			if (a >= 0 && a < H && b >= 0 && b < W && arr_main[a][b] == BLANK)
			{
				//fill_hole(a, b);
				stack_push(a, b);
			}
		}
	}
}

void mark(int x, int y)
{
	int i, a, b;
	int dir[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
	
	stack_init_line();
	stack_push_line(x, y);
	
	while (!stack_is_empty_line())
	{
		stack_pop_line(&x, &y);
		arr_main[x][y] = FILLED;
	
		for (i = 0; i < 4; i++)
		{
			a = x + dir[i][0];
			b = y + dir[i][1];
			if (a >= 0 && a < H && b >= 0 && b < W)
			{
				if (arr_main[a][b] == BLANK)
				{
					fill_hole(a, b);
					++hole_count;
				}
				else if (arr_main[a][b] == LINE)
				{
					//mark(a, b);
					stack_push_line(a, b);
				}
			}
		}
	}
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int i, j, k, l, v;
	char ch;
	int case_no = 1;
	while (scanf("%d %d", &H, &W) == 2)
	{
		if (H == 0 && W == 0)
			return 0;
		gets(arr_inp[0]);
		for (i = 0; i < H; i++)
		{
			gets(arr_inp[i]);
			j = k = 0;
			
			while (arr_inp[i][j])
			{
				ch = arr_inp[i][j];
				v = 0;
				
				if (ch >= '0' && ch <= '9')
					v = ch - '0';
				else if (ch >= 'a' && ch <= 'f')
					v = ch - 'a' + 10;

				for (l = 0; l < 4; l++)
					arr_main[i][k++] = arr_decode[v][l];
				
				j++;
			} // end while
		} // end for

		W *= 4;
		for (i = 0; i < TOTAL_SYMBOL; i++)
			found[i] = 0;

		for (i = 0; i < H; i++)
		{
			for (j = 0; j < W; j++)
			{
				traversed[i][j] = false;
			}
		}

		for (i = 0; i < H; i++)
		{
			if (arr_main[i][0] == BLANK)
			{
				fill_hole(i, 0);
			}
			if (arr_main[i][W - 1] == BLANK)
			{
				fill_hole(i, W - 1);
			}
		}

		for (i = 0; i < W; i++)
		{
			if (arr_main[0][i] == BLANK)
			{
				fill_hole(0, i);
			}
			if (arr_main[H - 1][i] == BLANK)
			{
				fill_hole(H - 1, i);
			}
		}

		for (i = 0; i < H; i++)
		{
			for (j = 0; j < W; j++)
			{
				if (arr_main[i][j] == LINE)
				{
					hole_count = 0;
					mark(i, j);
					++found[hole_count];
				}
			}
		}
		printf("Case %d: ", case_no++);
		for (i = 0; i < TOTAL_SYMBOL; i++)
		{
			v = found[holes[i]];
			if (v > 0)
			{
				for (j = 0; j < v; j++)
					printf("%c", sym[i]);
			}
		}
		printf("\n");
	} // end while inp
	return 0;
}


/*
Ankh: A // 1 hole
Wedjat: J //3 holes
Djed: D //5 holes
Scarab: S //4 holes
Was: W // 0 hole
Akhet: K // 2 holes
*/

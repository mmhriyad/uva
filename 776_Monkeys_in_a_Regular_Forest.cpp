#include <stdio.h>

#define MAXN 1000

int arr[MAXN][MAXN], col_width[MAXN];
char carr[MAXN][MAXN];
const char ch_visited = ' ';
int count = 0, N = 0, M = 0, total_marked = 0, total;

void fill(int x, int y, char ch)
{
	int i, a, b;
	int dir[8][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }, { -1, -1 }, { 1, -1 }, { -1, 1 }, { 1, 1 } };
	arr[x][y] = count;
	carr[x][y] = ch_visited;
	++total_marked;
	if (total == total_marked)
		return;
	for (i = 0; i < 8; i++)
	{
		a = dir[i][0] + x;
		b = dir[i][1] + y;
		if (a >= 0 && a < N && b >= 0 && b < M && (carr[a][b] == ch))
			fill(a, b, ch);
		if (total == total_marked)
			return;
	}

}

void print_arr()
{
	int i, j, colw, val;
	for (j = 0; j < M; j++)
	{
		col_width[j] = 1;
		for (i = 0; i < N; i++)
		{
			/*if (arr[i][j] < 10)
				colw = 1;
			else if (arr[i][j] < 100)
				colw = 2;
			else colw = 3;
			if (colw > col_width[j])
				col_width[j] = colw;*/
			val = arr[i][j];
			colw = 0;
			while (val)
			{
				val /= 10;
				++colw;
			}
			if (colw > col_width[j])
				col_width[j] = colw;
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			char format[10];
			if (j == 0)
			{
				sprintf(format, "%%%dd", col_width[j]);
			}
			else
			{
				sprintf(format, " %%%dd", col_width[j]);
			}
			printf(format, arr[i][j]);
		}
		printf("\n");
	}
	printf("%%\n");
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	char inp[MAXN * 2 + 1], ch;
	int i, j, k;
	while (1)
	{
		/*for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				arr[i][j] = 0;
				carr[i][j] = 0;
			}
		}*/
		i = 0;
		while (gets(inp))
		{
			if (inp[0] == '%')
				break;
			j = k = 0;
			while (inp[j])
			{
				ch = inp[j];
				if (ch != ' ')
					carr[i][k++] = ch;
				j++;
			}
			i++;
		}
		N = i;
		M = k;
		count = total_marked = 0;
		total = N * M;
		for (i = 0; i < N && total_marked < total; i++)
		{
			for (j = 0; j < M && total_marked < total; j++)
			{
				if (carr[i][j] != ch_visited)
				{
					count++;
					fill(i, j, carr[i][j]);
				}
			}
		}
		print_arr();
		if (inp[0] != '%')
			break;
	}
	return 0;
}
#include <stdio.h>
#include <string.h>

#define MAX_CHAR 82 //minimum
#define MAX_LINE 32 //minimum. < 32 will be WA

char arr[MAX_LINE][MAX_CHAR];
int T, N, M, cx, cy;
char contor;

int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

void fill_blanks()
{
	int i, j;
	for (i = 0; i < MAX_LINE; i++)
		for (j = 0; j < MAX_CHAR; j++)
			if (!arr[i][j])
				arr[i][j] = ' ';
}

void remove_trail_spaces()
{
	int i, j;
	for (i = 0; i < MAX_LINE; i++)
		for (j = MAX_CHAR - 1; j >= 0; j--)
			if (arr[i][j] == ' ')
				arr[i][j] = 0;
			else
				break;
}

void fill(int x, int y)
{
	int i, a, b;
	arr[x][y] = '#';
	for (i = 0; i < 4; i++)
	{
		a = dir[i][0] + x;
		b = dir[i][1] + y;
		if ((a >= 0 && a < N) && (b >= 0 && b < M) && (arr[a][b] == ' '))
			fill(a, b);
	}
}

void remove_rest(int x, int y)
{
	int i, j, k, a, b;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (arr[i][j] == '#')
			{
				for (k = 0; k < 4; k++)
				{
					a = i + dir[k][0];
					b = j + dir[k][1];
					if ((a >= 0 && a < N) && (b >= 0 && b < M) && arr[a][b] == contor)
					{
						break;
					}
				}
				if (k == 4)
					arr[i][j] = ' ';
			}
		}
	}
}

void print_arr()
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		puts(arr[i]);
		/*j = 0;
		while (arr[i][j])
		{
			printf("%c", arr[i][j]);
			j++;
		}
		printf("\n");
		*/
	}
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	int i, j, x = -1, y = -1;
	char ch;
	M = N = 0;
	scanf("%d", &T);
	gets(arr[0]);
	while (T--)
	{
		for (i = 0; i < N; i++)
			for (j = 0; j < M; j++)
				arr[i][j] = 0;
		N = M = 0;
		x = y = -1;
		contor = 0;
		while (1)
		{
			gets(arr[N]);
			i = 0;
			while (arr[N][i])
			{
				ch = arr[N][i];
				//tmp[N][i] = ch;
				if (x < 0)
				{
					if (ch == '*')
					{
						x = N;
						y = i;
					}
				}
				if (!contor)
				{
					if (ch != ' ' && ch != '_' && ch != '*' && ch != '#')
						contor = ch;
				}
				i++;
			}
			if (i > M)
				M = i;
			if (arr[N][0] == '_')
				break;
			N++;
		}
		N++;
		M++;
		cx = cy = -1;
		arr[x][y] = ' ';
		fill_blanks();
		fill(x, y);
		remove_rest(x, y);
		remove_trail_spaces();
		print_arr();
	}

	return 0;
}
#include <stdio.h>
#include <string.h>

#define MAXN 10

#define INC "inc"
#define DEC "dec"
#define TRANS "transpose"

char arr[MAXN][MAXN + 1];

int N;

void increament()
{
	int i, j;
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			++arr[i][j];
			if (arr[i][j] > '9')
				arr[i][j] = '0';
		}
	}
}

void decrement()
{
	int i, j;
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			--arr[i][j];
			if (arr[i][j] < '0')
				arr[i][j] = '9';
		}
	}
}

void swap_row(int a, int b)
{
	int i;
	char tmp;
	for (i = 0; i < N; ++i)
	{
		tmp = arr[a][i];
		arr[a][i] = arr[b][i];
		arr[b][i] = tmp;
	}
}

void swap_col(int a, int b)
{
	int i;
	char tmp;
	for (i = 0; i < N; ++i)
	{
		tmp = arr[i][a];
		arr[i][a] = arr[i][b];
		arr[i][b] = tmp;
	}
}

void transpose()
{
	int i, j;
	char tmp[MAXN][MAXN];
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			tmp[j][i] = arr[i][j];
		}
	}
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			arr[i][j] = tmp[i][j];
		}
	}
}

void print_arr()
{
	int i;
	for (i = 0; i < N; ++i)
	{
		puts(arr[i]);
	}
	printf("\n");
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T, M, cn, i, j, a, b;
	char inp[10000];
	scanf("%d", &T);
	for (cn = 1; cn <= T; ++cn)
	{
		scanf("%d", &N);
		gets(arr[0]);
		for (i = 0; i < N; ++i)
			gets(arr[i]);
		scanf("%d", &M);
		gets(inp);
		while (M--)
		{
			gets(inp);
			if (!strcmp(inp, INC))
				increament();
			else if (!strcmp(inp, DEC))
				decrement();
			else if (!strcmp(inp, TRANS))
				transpose();
			else if (inp[0] == 'r' && inp[1] == 'o' && inp[2] == 'w')
			{
				a = inp[4] - '0' - 1;
				b = inp[6] - '0' - 1;
				swap_row(a, b);
			}
			else
			{
				a = inp[4] - '0' - 1;
				b = inp[6] - '0' - 1;
				swap_col(a, b);
			}
		}
		printf("Case #%d\n", cn);
		print_arr();
	}
	return 0;
}
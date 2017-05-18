#include <stdio.h>

#define MAXN 1000

bool possible = false;
int arr[MAXN][MAXN], result[MAXN];
int N;

void mark(int x, int y, int val)
{
	int i, j;

	for (i = 0; i < N; i++)
	{
		arr[i][y] += val;
		arr[x][i] += val;
	}
	for (i = 0; i < N; i++)
	{
		if (x + i < N && y + i < N)
			arr[x + i][y + i] += val;
		if (x - i >= 0 && y - i >= 0)
			arr[x - i][y - i] += val;
		if (x - i >= 0 && y + i < N)
			arr[x - i][y + i] += val;
		if (x + i < N && y - i >= 0)
			arr[x + i][y - i] += val;
	}
}

void backtrack(int j)
{
	if (j == N || possible)
	{
		possible = true;
		return;
	}
	int i;
	for (i = 0; i < N; i++)
	{
		if (arr[i][j] == 0)
		{
			mark(i, j, 1);
			result[j] = i;
			backtrack(j + 1);
			if (possible)
				return;
			result[j] = -1;
			mark(i, j, -1);
		}
	}
}

void print_result()
{
	int i;
	for (i = 0; i < N; i++)
	{
		if (i > 0)
			printf(" ");
		printf("%d", result[i] + 1);
	}
	printf("\n");
}

void init()
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		result[i] = -1;
		for (j = 0; j < N; j++)
			arr[i][j] = 0;
	}
}

int main()
{
	freopen("inp.txt", "r", stdin);
	
	while (scanf("%d", &N) == 1)
	{
		init();
		possible = false;
		backtrack(0);
		if (possible)
		{
			print_result();
		}
		else
		{
			printf("Impossible\n");
		}
	}

	return 0;
}
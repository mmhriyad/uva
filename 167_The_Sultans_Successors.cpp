#include <stdio.h>

int fill[8][8], board[8][8];
bool col[8], diag1[15], diag2[15];
int max_sum;

void fillf(int x, int y, int val)
{
	int i, j;
	for (i = 0; i < x; ++i)
		fill[i][y] += val;
	for (i = x; i < 8; ++i)
		fill[i][y] += val;

	for (i = 0; i < y; ++i)
		fill[x][i] += val;
	for (i = y; i < 8; ++i)
		fill[x][i] += val;

	fill[x][y] -= val;

	for (i = x, j = y; i < 8 && j < 8; ++i, ++j)
		fill[i][j] += val;
	for (i = x - 1, j = y - 1; i >= 0 && j >= 0; --i, --j)
		fill[i][j] += val;

	fill[x][y] -= val;

	for (i = x, j = y; i < 8 && j >= 0; ++i, --j)
		fill[i][j] += val;
	for (i = x - 1, j = y + 1; i >= 0 && j < 8; --i, ++j)
		fill[i][j] += val;

	fill[x][y] -= val;
}

void fill2(int x, int y, bool val)
{
	col[y] = val;
	diag1[x - y + 7] = val;
	diag2[x + y] = val;
}

void backtrack(int r, int sum)
{
	if (r > 7)
	{
		if (sum > max_sum)
			max_sum = sum;
		return;
	}
	int i = r, j;
	for (j = 0; j < 8; ++j)
	{
		if (fill[i][j] == 0)
		{
			fillf(i, j, 1);
			backtrack(i + 1, sum + board[i][j]);
			fillf(i, j, -1);
		}
	}
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int N, i, j;
	scanf("%d", &N);
	while (N--)
	{
		for (i = 0; i < 8; ++i)
		{
			for (j = 0; j < 8; ++j)
			{
				scanf("%d", &board[i][j]);
				fill[i][j] = 0;
			}
		}

		max_sum = 0;
		backtrack(0, 0);
		printf("%5d\n", max_sum);
	}
	return 0;
}
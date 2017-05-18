#include <stdio.h>
#include <stdlib.h>

#define MAXN 100

int arrv1[MAXN][MAXN], arrv2[MAXN][MAXN];
int arrh1[MAXN][MAXN], arrh2[MAXN][MAXN];
int sarr1[MAXN * MAXN], sarr2[MAXN * MAXN];
int W = 0, H = 0, N = 0, count = 0;

int sortf(const void *a, const void *b)
{
	int *val1 = (int *)a;
	int *val2 = (int *)b;
	return (*val1 - *val2);
}

void fill_verti(int x, int y, bool first_array)
{
	int i, a, b;
	int dir[4][2] = { { 1, 0 }, { -1, 0 }};
	++count;
	if (first_array)
		arrv1[x][y] = 0;
	else
		arrv2[x][y] = 0;
	for (i = 0; i < 2; i++)
	{
		a = x + dir[i][0];
		b = y + dir[i][1];
		if (a >= 0 && a < W && b >= 0 && b < H && ((first_array && arrv1[a][b]) || (!first_array && arrv2[a][b])))
		{
			fill_verti(a, b, first_array);
		}
	}
}

void fill_hori(int x, int y, bool first_array)
{
	int i, a, b;
	int dir[2][2] = { { 0, 1 }, { 0, -1 } };
	++count;
	if (first_array)
		arrh1[x][y] = 0;
	else
		arrh2[x][y] = 0;
	for (i = 0; i < 2; i++)
	{
		a = x + dir[i][0];
		b = y + dir[i][1];
		if (a >= 0 && a < W && b >= 0 && b < H && ((first_array && arrh1[a][b]) || (!first_array && arrh2[a][b])))
		{
			fill_hori(a, b, first_array);
		}
	}
}

int main()
{
	freopen("inp.txt", "r", stdin);
	int T, num1, num2, i, j, a, b;
	scanf("%d", &T);
	while (T--)
	{
		for (i = 0; i < W; i++)
		{
			for (j = 0; j < H; j++)
			{
				arrh1[i][j] = arrh2[i][j] = arrv1[i][j] = arrv2[i][j] = 0;
			}
		}

		scanf("%d %d %d", &W, &H, &N);

		for (i = 0; i < N; i++)
		{
			scanf("%d %d", &a, &b);
			arrh1[a][b] = arrv1[a][b] = 1;
		}
		for (i = 0; i < N; i++)
		{
			scanf("%d %d", &a, &b);
			arrh2[a][b] = arrv2[a][b] = 1;
		}

		num1 = 0;
		for (i = 0; i < W; i++)
		{
			for (j = 0; j < H; j++)
			{
				if (arrh1[i][j])
				{
					count = 0;
					fill_hori(i, j, true);
					sarr1[num1++] = count;
				}
				if (arrv1[i][j])
				{
					count = 0;
					fill_verti(i, j, true);
					sarr1[num1++] = count;
				}
			}
		}

		num2 = 0;
		for (i = 0; i < W; i++)
		{
			for (j = 0; j < H; j++)
			{
				if (arrh2[i][j])
				{
					count = 0;
					fill_hori(i, j, false);
					sarr2[num2++] = count;
				}
				if (arrv2[i][j])
				{
					count = 0;
					fill_verti(i, j, false);
					sarr2[num2++] = count;
				}
			}
		}

		if (num1 == num2)
		{
			qsort(sarr1, num1, sizeof(int), sortf);
			qsort(sarr2, num1, sizeof(int), sortf);
			for (i = 0; i < num1; i++)
			{
				if (sarr1[i] != sarr2[i])
					break;
			}
			if (i == num1)
				puts("YES");
			else
				puts("NO");
		}
		else
			puts("NO");

	}
	return 0;
}
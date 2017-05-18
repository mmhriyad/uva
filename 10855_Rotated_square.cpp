#include <stdio.h>

#define MAXN 1000

char arr_big[MAXN][MAXN], arr_small[MAXN][MAXN];

int N, n;
int count0, count90, count180, count270;

void find(int starti, int startj)
{
	int leni = starti + n;
	int lenj = startj + n;
	int i, j, k, l;
	bool is0, is90, is180, is270;
	
	is0 = is90 = is180 = is270 = true;
	
	for (i = starti, k = 0; i < leni; ++i, ++k)
	{
		for (j = startj, l = 0; j < lenj; ++j, ++l)
		{
			if (is0 && (arr_big[i][j] != arr_small[k][l]))
				is0 = false;
			if (is90 && (arr_big[i][j] != arr_small[n - l - 1][k]))
				is90 = false;
			if (is180 && (arr_big[i][j] != arr_small[n - k - 1][n - l - 1]))
				is180 = false;
			if (is270 && (arr_big[i][j] != arr_small[l][n - k - 1]))
				is270 = false;
		}
	}

	count0 += is0;
	count90 += is90;
	count180 += is180;
	count270 += is270;
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int i, j, len;
	while (scanf("%d %d", &N, &n) == 2)
	{
		if (N == 0 && n == 0)
			break;
		gets(arr_big[0]);
		for (i = 0; i < N; ++i)
			gets(arr_big[i]);
		for (i = 0; i < n; ++i)
			gets(arr_small[i]);
		len = N - n + 1;
		count0 = count90 = count180 = count270 = 0;
		for (i = 0; i < len; ++i)
		{
			for (j = 0; j < len; ++j)
			{
				find(i, j);
			}
		}
		printf("%d %d %d %d\n", count0, count90, count180, count270);
	}
}
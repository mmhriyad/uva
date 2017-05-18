#include <stdio.h>

#define GET_MAX(x,y) (x > y ? x : y)

#define MAXN 101
int N, arr[MAXN][MAXN];

int get_sum(int x, int y, int maxx, int maxy)
{
	int i, j;
	int sum = 0;
	for (i = x; i <= maxx; i++)
	{
		for (j = y; j <= maxy; j++)
		{
			sum += arr[i][j];
		}
	}
	return sum;
}

int main()
{
	freopen("inp.txt", "r", stdin);
	int i, j, l, m;
	int max = 0;
	while (scanf("%d", &N) == 1)
	{
		max = 0;
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				scanf("%d", &arr[i][j]);
				for (l = 0; l <= i; l++)
				{
					for (m = 0; m <= j; m++)
					{
						max = GET_MAX(max, get_sum(l, m, i, j));
					}
				}
			}
		}

		printf("%d\n",max);
	}

	return 0;
}
#include <stdio.h>
#define MAXN 100

int arr[MAXN][MAXN];
int N;

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int i, j, row_count, col_count, count;

	int flip_x, flip_y;

	while (scanf("%d", &N) == 1 && N)
	{
		row_count = 0;
		for (i = 0; i < N; ++i)
		{
			count = 0;
			for (j = 0; j < N; ++j)
			{
				scanf("%d", &arr[i][j]);
				count += arr[i][j];
			}
			if (count % 2)
			{
				++row_count;
				flip_x = i;
			}
		}

		if (row_count > 1)
			printf("Corrupt\n");
		else
		{
			col_count = 0;
			for (j = 0; j < N; ++j)
			{
				count = 0;
				for (i = 0; i < N; ++i)
				{
					count += arr[i][j];
				}
				if (count % 2)
				{
					++col_count;
					flip_y = j;
					if (col_count > 1 || row_count == 0)
					{
						printf("Corrupt\n");
						break;
					}
				}
			}

			if (row_count == 0 && col_count == 0)
			{
				printf("OK\n");
			}
			else if (row_count == 1 && col_count == 1)
			{
				printf("Change bit (%d,%d)\n", flip_x + 1, flip_y + 1);
			}
		}
	}
}
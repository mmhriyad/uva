#include <stdio.h>

int possible[100][8], totalFound = 0;
bool rows[8] = { false, }, diag1[16] = { false, }, diag2[16] = {false, };

void fill(int x, int y, bool val)
{
	rows[x] = val;
	diag1[x + y] = val;
	diag2[x - y + 7] = val;
}

void makeboard(int col, int arr[])
{
	int i;
	if (col == 8)
	{
		for (i = 0; i < 8; ++i)
			possible[totalFound][i] = arr[i] + 1;
		++totalFound;
		return;
	}
	for (i = 0; i < 8; ++i)
	{
		if (rows[i] == false && diag1[col + i] == false && diag2[i - col + 7] == false)
		{
			arr[col] = i;
			fill(i, col, true);
			makeboard(col + 1, arr);
			fill(i, col, false);
		}
	}
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int arr[8];
	makeboard(0, arr);
	int i, k, T, x, y;
	int cn = 0;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &x, &y);
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		cn = 0;
		for (k = 0; k < totalFound; ++k)
		{
			if (possible[k][y-1] == x)
			{
				printf("%2d     ", ++cn);
				for (i = 0; i < 8; ++i)
					printf(" %d", possible[k][i]);
				printf("\n");
			}
		}
		if (T)
			printf("\n");

		printf("");
	}
	return 0;
}
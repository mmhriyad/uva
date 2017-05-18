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
	/*freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int arr[8];
	makeboard(0, arr);
	int i, k, sum, min;
	int cn = 0;
	while (scanf("%d", &arr[0]) == 1)
	{
		++cn;
		for (i = 1; i < 8; ++i)
			scanf("%d", &arr[i]);

		min = 1 << 30;
		for (k = 0; k < totalFound; ++k)
		{
			sum = 0;
			for (i = 0; i < 8; ++i)
			{
				/*int a = possible[k][i];
				int diff = (a > arr[i] ? a - arr[i] : arr[i] - a);
				sum += diff;*/
				if (possible[k][i] != arr[i])
					++sum;
			}
			if (sum < min)
				min = sum;
		}

		printf("Case %d: %d\n", cn, min);
	}
	return 0;
}
#include <stdio.h>

#define MAXL 9

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int arr[MAXL][MAXL];
	int T, i, j, len;
	scanf("%d", &T);
	while (T--)
	{
		for (i = MAXL-1; i >= 0; i -= 2)
		{
			len = MAXL - i;
			for (j = 0; j < len; j += 2)
			{
				scanf("%d", &arr[i][j]);
			}
		}

		for (i = 0; i < MAXL - 1; i += 2)
		{
			len = MAXL - i;
			for (j = 1; j < len; j += 2)
			{
				arr[i][j] = (arr[i + 2][j - 1] - arr[i][j - 1] - arr[i][j + 1]) / 2;
				arr[i + 1][j - 1] = arr[i][j - 1] + arr[i][j];
				arr[i + 1][j] = arr[i][j + 1] + arr[i][j];
			}
		}

		for (i = MAXL - 1; i >= 0; --i)
		{
			len = MAXL - i;
			for (j = 0; j < len; ++j)
			{
				printf("%d", arr[i][j]);
				if (j < len - 1)
					printf(" ");
			}
			printf("\n");
		}
	}
}
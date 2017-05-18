#include <stdio.h>

#define MAXN 10000

int arr[MAXN][10];

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int i, N, j, k;
	char str[10];
	for (i = 0; i < 10; ++i)
		arr[0][i] = 0;
	for (i = 1; i < MAXN; ++i)
	{
		for (j = 0; j < 10; ++j)
			arr[i][j] = arr[i - 1][j];

		j = i;
		while (j)
		{
			k = j % 10;
			++arr[i][k];
			j /= 10;
		}
	}
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		for (i = 0; i < 10; ++i)
		{
			if (i)
				printf(" %b", arr[N][i]);
			else
				printf("%d", arr[N][i]);
		}
		printf("\n");
	}
	return 0;
}
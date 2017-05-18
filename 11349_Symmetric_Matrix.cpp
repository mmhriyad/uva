#include <stdio.h>

#define MAXN 101

typedef long long int lli;

lli arr[MAXN][MAXN];

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int N, T, i, j, cn, mid;
	bool is_sym;
	char c;
	scanf("%d", &T);
	
	for (cn = 1; cn <= T; ++cn)
	{
		getchar();
		scanf("N = %d", &N);
		is_sym = true;
		mid = (N + 1) / 2;
		for (i = 0; i < N; ++i)
		{
			for (j = 0; j < N; ++j)
			{
				scanf("%lld", &arr[i][j]);
				if (arr[i][j] < 0)
					is_sym = false;
			}
		}

		for (i = 0; i < mid; ++i)
		{
			for (j = 0; j < N; ++j)
			{
				if (arr[i][j] - arr[N - i - 1][N - j - 1])
				{
					is_sym = false;
					break;
				}
			}
			if (!is_sym)
				break;
		}
		printf("Test #%d: ", cn);
		if (is_sym)
			printf("Symmetric.\n");
		else
			printf("Non-symmetric.\n");
	}
	return 0;
}
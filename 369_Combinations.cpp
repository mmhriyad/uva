#include <stdio.h>

#define MAXN 101

typedef unsigned long long int lli;

lli pt[MAXN][MAXN];

void build_pt()
{
	int i, k;
	pt[0][0] = 1;
	pt[1][0] = pt[1][1] = 1;
	for (i = 2; i < MAXN; ++i)
	{
		pt[i][0] = pt[i][i] = 1;
		for (k = 1; k < i; ++k)
		{
			pt[i][k] = pt[i - 1][k - 1] + pt[i - 1][k];
		}
	}

}

int main()
{
	/*freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	build_pt();
	int N, M;
	while (scanf("%d %d", &N, &M) == 2)
	{
		if (M == 0 && N == 0)
			break;
		printf("%d things taken %d at a time is %lld exactly.\n", N, M, pt[N][M]);
	}
	return 0;
}
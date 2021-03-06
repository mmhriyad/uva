#include <stdio.h>

#define MAXN 10001
#define INF 999999

int min[MAXN], max;
int squares[101] = { 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225, 256, 289, 324, 361, 400, 
441, 484, 529, 576, 625, 676, 729, 784, 841, 900, 961, 1024, 1089, 1156, 1225, 1296, 1369, 1444, 1521, 1600,
1681, 1764, 1849, 1936, 2025, 2116, 2209, 2304, 2401, 2500, 2601, 2704, 2809, 2916, 3025, 3136, 3249, 3364, 3481, 3600, 
3721, 3844, 3969, 4096, 4225, 4356, 4489, 4624, 4761, 4900, 5041, 5184, 5329, 5476, 5625, 5776, 5929, 6084, 6241, 6400, 
6561, 6724, 6889, 7056, 7225, 7396, 7569, 7744, 7921, 8100, 8281, 8464, 8649, 8836, 9025, 9216, 9409, 9604, 9801, 10000};

void dp(int n)
{
	int i, j;
	for(i=max; i<=n; i++)
	{
		for(j=0; squares[j]<=i && j<100; j++)
		{
			if(min[i] > (min[i-squares[j]] + 1))
				min[i] = min[i-squares[j]] + 1;
		}
	}
	max = n;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int T, a, i;
	max = 1;
	
	for(i=1; i<MAXN; i++)
		min[i] = INF;

	min[0] = 0;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &a);
		if(a >= max)
			dp(a);
		max = a;
		printf("%d\n", min[a]);
	}
}
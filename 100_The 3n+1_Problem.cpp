#include <stdio.h>

#define MAXN 100000
#define MAXM 5000

int arr[MAXN];
int mem[MAXM][MAXN];

int getcount(int n)
{
	int count = 1;
	while(n != 1)
	{
		count++;

		if(n&1)
			n = 3*n + 1;
		else
			n = n>>1;
	}
	//printf("%d, ", count);
	return count;
}
#define GETMAX(x,y) (x>y ? x : y)

int main()
{
	freopen("input.txt", "r", stdin);
	int i, j, cnt, max = 0, a, b, res;
	arr[0] = 0;
	for(i=1; i<MAXN; i++)
	{
		cnt = getcount(i);
		arr[i] = cnt;
		mem[i][i] = cnt;
		max = GETMAX(max, cnt);
		for(j=i-1; j>=1; j--)
		{
			mem[j][i] = GETMAX(cnt, mem[j][i-1]);
		}
	}

	while(scanf("%d %d", &a, &b) == 2)
	{
		if(a > b)
			res = mem[b][a];
		else
			res = mem[a][b];
		printf("%d %d %d\n", a, b, res);
	}
	
	return 0;
}
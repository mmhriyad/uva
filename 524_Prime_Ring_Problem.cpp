#include <stdio.h>
#include <string.h>

#define MAXN 21

int arr[MAXN];
bool taken[MAXN], isprime[] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1};

int N;

void print()
{
	int i;
	printf("1");
	for(i=1; i<N; i++)
		printf(" %d", arr[i]);
	printf("\n");
}

void solve(int p)
{
	int i;
	if(p == N)
	{
		print();
		return;
	}
	for(i=2; i<=N; i++)
	{
		if(!taken[i] && ((p<N-1 && isprime[i+arr[p-1]]) || (p==N-1 && isprime[i+arr[0]] && isprime[i+arr[p-1]])))
		{
			taken[i] = true;
			arr[p] = i;
			solve(p+1);
			taken[i] = false;
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int caseno = 1;
	while(scanf("%d", &N) == 1)
	{
		memset(arr, 0, sizeof(arr));
		memset(taken, false, sizeof(taken));
		arr[0] = 1;
		if(caseno>1)
			printf("\n");
		printf("Case %d:\n", caseno++);
		solve(1);		
	}
	return 0;
}
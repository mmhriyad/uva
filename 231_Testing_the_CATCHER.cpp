#include <stdio.h>

#define MAXN 33000

int arr[MAXN], N, max_count;
bool taken[MAXN];

void solve(int p, int count)
{
	int i;
	if(max_count < count)
		max_count = count;
	if(p == N)
		return;
	for(i=p+1; i<N; i++)
	{
		if(!taken[i] && arr[i] <= arr[p])
		{
			taken[i] = true;
			solve(i, count+1);
			taken[i] = false;
		}
	}

}

int main()
{
	freopen("input.txt", "r", stdin);
	int a, T, i;
	N = 0, T = 1;
	for(;;)
	{
		scanf("%d", &a);
		if(a == -1)
		{
			if(N==0)
				return 0;
			else
			{
				max_count = 0;
				for(i=0; i<N; i++)
					solve(i, 1);
				if(T>1)
					printf("\n");
				printf("Test #%d:\n  maximum possible interceptions: %d\n", T++, max_count);
				N = 0;
			}
		}
		else
		{
			arr[N++] = a;
		}
	}
}
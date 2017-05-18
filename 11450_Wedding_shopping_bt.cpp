#include <stdio.h>

#define MAXI 21

int item[MAXI][MAXI];
bool taken[MAXI][MAXI], possible;

int T, nitems, M, C, max_amount;

void solve(int amount, int count)
{
	if(count == C)
	{
		if(max_amount < amount)
			max_amount = amount;
		possible = true;
		return;
	}
	
	int i, j;
	i = count;

	for(j=1; j<=item[i][0]; j++)
	{
		if(item[i][j]+amount <= M)
		{
			solve(item[i][j]+amount, i+1);
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	
	int i, j;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &M, &C);
		for(i=0; i<C; i++)
		{
			scanf("%d", &nitems);
			item[i][0] = nitems;
			for(j = 1; j <= nitems; j++)
				scanf("%d", &item[i][j]);
		}
		max_amount = 0;
		possible = false;
		solve(0,0);
		if(possible)
			printf("%d\n", max_amount);
		else
			printf("no solution\n");
	}
}
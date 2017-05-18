//624 - CD
#include <stdio.h>

#define MAXSOL 10000
#define MAXT 21

int sol[MAXSOL][MAXT], tracks[MAXT];
bool taken[MAXT];
int N, T, ns, nt, max_index, max, total_track;

void init()
{
	int i;
	for (i = 0; i < MAXT; ++i)
		taken[i] = false;
	nt = 0;
}

bool backtrack(int start, int sum)
{
	int i, k;
	if (max == N)
		return true;
	if (sum == N)
	{
		max_index = ns;
		max = sum;
		total_track = nt;
		//++ns;
		return true;
	}
	for (i = start; i < T; ++i)
	{
		if (nt == 0 && i > start)
			return false;
		if (sum + tracks[i] > N)
		{
			/*for (k = 0; k < nt; ++k)
				sol[ns + 1][k] = sol[ns][k];*/
			if (max < sum)
			{
				max_index = ns;
				max = sum;
				total_track = nt;
				for (k = 0; k < nt; ++k)
					sol[ns + 1][k] = sol[ns][k];
				++ns;
			}
			//++ns;
			continue;
		}
		if (!taken[i])
		{
			taken[i] = true;
			sol[ns][nt++] = tracks[i];
			backtrack(i + 1, sum + tracks[i]);
			--nt;
			taken[i] = false;
		}
		if (max == N)
			return true;
	}
	//++ns;
	if (max < sum)
	{
		max_index = ns;
		max = sum;
		total_track = nt;
		for (k = 0; k < nt; ++k)
			sol[ns + 1][k] = sol[ns][k];
		++ns;
	}
	return true;
}

int main()
{
	/*freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/

	int i, sum;
	while (scanf("%d %d", &N, &T) == 2)
	{
		for (i = 0; i < T; ++i)
		{
			scanf("%d", &tracks[i]);
		}
		ns = 0;
		max = 0;
		total_track = 0;
		for (i = 0; i < T; ++i)
		{
			if (tracks[i] <= N)
			{
				init();
				backtrack(i, 0);
				++ns;
				if (max == N)
					break;
			}
		}
		sum = 0;
		for (i = 0; i < total_track; ++i)
		{
			//sum += sol[max_index][i];
			//if (sum <= max && sol[max_index][i])
				printf("%d ", sol[max_index][i]);
		}
		if (max == 0)
			printf("0 ");
		printf("sum:%d\n", max);
	}
}
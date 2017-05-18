#include <stdio.h>

#define MAXN 21

int arr[MAXN], sol[MAXN], stack[MAXN];
bool taken[MAXN], possible;

int N, P, max, max_count;

void update(int pos)
{
	int i;
	max_count = pos;
	for (i = 0; i < pos; ++i)
		sol[i] = stack[i];
}

void backtrack(int sum, int index, int pos)
{
	if (sum == N || pos == P)
	{
		possible = true;
		max = sum;
		update(pos);
		return;
	}
	if (sum > max)
	{
		max = sum;
		update(pos);
	}
	int i;
	for (i = index; i < P; ++i)
	{
		if (!taken[i] && ((sum + arr[i]) <= N))
		{
			taken[i] = true;
			stack[pos] = arr[i];
			backtrack(sum + arr[i], i + 1, pos + 1);
			taken[i] = false;
		}
		if (possible)
			return;
	}
}

void init()
{
	int i;
	for (i = 0; i < P; ++i)
		taken[i] = false;
	possible = false;
	max = 0;
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int i;
	while (scanf("%d", &N) == 1)
	{
		scanf("%d", &P);
		for (i = 0; i < P; ++i)
			scanf("%d", &arr[i]);
		init();
		backtrack(0, 0, 0);
		for (i = 0; i < max_count; ++i)
			printf("%d ", sol[i]);
		printf("sum:%d\n", max);
	}
	return 0;
}
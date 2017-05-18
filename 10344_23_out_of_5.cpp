#include <stdio.h>

#define N 5
#define RESULT 23

bool possible = false;
int nums[N], current[N];
bool taken[N];

bool isPossible(int res, int pos)
{
	if (pos == N)
	{
		return (res == RESULT);
	}
	if (isPossible(res + current[pos], pos + 1))
		return true;
	if (isPossible(res - current[pos], pos + 1))
		return true;
	if (isPossible(res * current[pos], pos + 1))
		return true;
	return false;
}

void backtrack(int count)
{
	if (count == N)
	{
		possible = isPossible(current[0], 1);
		return;
	}
	int i;
	for (i = 0; i < N && !possible; ++i)
	{
		if (!taken[i])
		{
			taken[i] = true;
			current[count] = nums[i];
			backtrack(count + 1);
			taken[i] = false;
		}
	}
}
int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int i, sum;
	while (true)
	{
		sum = 0;
		for (i = 0; i < N; ++i)
		{
			taken[i] = false;
			scanf("%d", &nums[i]);
			sum += nums[i];
		}
		if (sum == 0)
			return 0;
		possible = false;
		backtrack(0);
		if (!possible)
			printf("Impossible\n");
		else
			printf("Possible\n");
	}
	return 0;
}
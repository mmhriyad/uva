#include <stdio.h>

#define MAXN 12

int num, N, ns;

int arr[MAXN], stack[MAXN];
bool taken[MAXN], found, started[101];

void init()
{
	int i;
	for (i = 0; i < MAXN; ++i)
		taken[i] = started[i] = false;
	for (; i < 101; ++i)
		started[i] = false;
	ns = 0;
	found = false;
}

bool backtrack(int start, int rem)
{
	bool f = false;
	if (rem == 0)
	{
		int k;
		for (k = 0; k < ns; ++k)
		{
			if (k == 0)
				printf("%d", stack[k]);
			else
				printf("+%d", stack[k]);
		}
		printf("\n");
		found = true;
		return true;
	}
	int i;
	for (i = start; i < N; ++i)
	{
		if (ns == 0 && (arr[i] > rem || i > start))
			return f;
		if (!taken[i] && arr[i] <= rem)
		{
			taken[i] = true;
			stack[ns++] = arr[i];
			if (backtrack(i + 1, rem - arr[i]))
			{
				int nn = arr[i];
				--ns;
				taken[i] = false;
				f = true;
				while (i < N && arr[i] == nn)
					++i;
				--i;
			}
			else
			{
				--ns;
				taken[i] = false;
			}
			/*if (rem == arr[i] && i == start)
				return;*/
		}
	}
	return f;
}

int main()
{
	/*freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int i;
	while (scanf("%d %d", &num, &N) == 2)
	{
		if (num == 0 && N == 0)
			break;
		init();
		for (i = 0; i < N; ++i)
			scanf("%d", &arr[i]);

		printf("Sums of %d:\n", num);
		
		for (i = 0; i < N; ++i)
		{
			if (!started[arr[i]])
			{
				ns = 0;
				backtrack(i, num);
				started[arr[i]] = true;
			}
		}
		if (!found)
			printf("NONE\n");
	}
	return 0;
}
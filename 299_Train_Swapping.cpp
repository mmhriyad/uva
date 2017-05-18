#include <stdio.h>

#define MAXN 1001

int N, arr[MAXN], flip_count;

void flip(int a, int b)
{
	int tmp = arr[b], i;
	for (i = b; i > a; --i)
	{
		arr[i] = arr[i - 1];
	}
	arr[a] = tmp;
	flip_count += (b - a);
}

void flip_sort()
{
	int min, min_pos;
	int i, j;
	flip_count = 0;
	for (i = 0; i < N - 1; i++)
	{
		min = arr[i];
		min_pos = -1;
		for (j = i + 1; j < N; j++)
		{
			if (min > arr[j])
			{
				min = arr[j];
				min_pos = j;
			}
		}
		if (min_pos > 0)
		{
			flip(i, min_pos);
		}
	}
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int i, T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		for (i = 0; i < N; i++)
		{
			scanf("%d", &arr[i]);
		}
		flip_sort();
		printf("Optimal train swapping takes %d swaps.\n", flip_count);
	}
	return 0;
}
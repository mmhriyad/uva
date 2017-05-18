#include <stdio.h>

#define MAXN 1001

int N, arr[MAXN], flip_count;

void flip2(int a, int b)
{
	int tmp, tmp_b = b;
	while (a < b)
	{
		tmp = arr[b - 1];
		arr[b - 1] = arr[b];
		arr[b] = tmp;
		--b;
	}
	flip_count += (tmp_b - a);
}

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
	int i;
	while (scanf("%d", &N) == 1)
	{
		for (i = 0; i < N; i++)
		{
			scanf("%d", &arr[i]);
		}
		flip_sort();
		printf("Minimum exchange operations : %d\n", flip_count);
	}
	return 0;
}
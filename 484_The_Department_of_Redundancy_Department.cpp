#include <stdio.h>

#define MAXN 100000

int arr_pos[MAXN], arr_neg[MAXN], N;

int numbers[MAXN];

void init()
{
	int i;
	for (i = 0; i < MAXN; ++i)
	{
		arr_neg[i] = arr_pos[i] = 0;
	}
	N = 0;
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int a, i, count;
	//init();
	N = 0;
	while (scanf("%d", &a) == 1)
	{
		if (a < 0)
		{
			++arr_neg[-a];
			if (arr_neg[-a] == 1)
				numbers[N++] = a;
		}
		else
		{
			++arr_pos[a];
			if (arr_pos[a] == 1)
				numbers[N++] = a;
		}
	}
	for (i = 0; i < N; ++i)
	{
		a = numbers[i];
		if (a < 0)
			count = arr_neg[-a];
		else
			count = arr_pos[a];
		printf("%d %d\n", a, count);
	}
}
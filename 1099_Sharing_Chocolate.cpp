#include <stdio.h>
#include <stdlib.h>

#define MAXN 15

int parts[MAXN], N, X, Y;

int sortf(const void *a, const void *b)
{
	int *num1 = (int *)a;
	int *num2 = (int *)b;

	return *num2 - *num1;
}

bool canBreak(int *x, int *y, int size)
{
	if (*x * *y < size)
		return false;
	int i;
	for (i = 1; i <= *x; i++)
	{
		if (*y * i == size)
		{
			*x -= i;
			return true;
		}
	}

	for (i = 1; i <= *y; i++)
	{
		if (*x * i == size)
		{
			*y -= i;
			return true;
		}
	}

	return false;
}

bool isPossible()
{
	int i, nx = X, ny = Y;
	for (i = 0; i < N; ++i)
	{
		if (!canBreak(&nx, &ny, parts[i]))
			return false;
	}
	return true;
}

int main()
{
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int i, caseno = 0;
	while (scanf("%d", &N) == 1 && N)
	{
		scanf("%d %d", &X, &Y);
		for (i = 0; i < N; ++i)
		{
			scanf("%d", &parts[i]);
		}
		qsort(parts, N, sizeof(int), sortf);
		printf("Case %d: ", ++caseno);
		if (isPossible())
			printf("Yes\n");
		else
			printf("No\n");
	}
}
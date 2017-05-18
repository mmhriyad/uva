#include <stdio.h>
#include <stdlib.h>

#define MAXN 10001

typedef struct
{
	long long int mod;
	bool isodd;
	long long int number;
}t_number;

t_number numbers[MAXN];

int N, M;

int sortf(const void *a, const void *b)
{
	t_number *n1 = (t_number *)a;
	t_number *n2 = (t_number *)b;

	long long int res;

	res = n1->mod - n2->mod;

	if (n1->mod == n2->mod)
	{
		if (n1->isodd && n2->isodd)
		{
			res = n2->number - n1->number;
		}
		else if(n1->isodd)
		{
			return -1;
		}
		else if (n2->isodd)
		{
			return 1;
		}
		else
		{
			res = n1->number - n2->number;
		}
	}

	if (res > 0)
		return 1;
	if (res < 0)
		return -1;
	return 0;
}

int main()
{
	/*freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/

	int a, i;

	while (scanf("%d %d", &N, &M) == 2)
	{
		printf("%d %d\n", N, M);
		if (N == 0 && M == 0)
		{
			return 0;
		}
		
		for (i = 0; i < N; ++i)
		{
			scanf("%d", &a);
			numbers[i].number = a;
			numbers[i].mod = a % M;
			numbers[i].isodd = a & 1;
		}
		qsort(numbers, N, sizeof(t_number), sortf);
		for (i = 0; i < N; ++i)
		{
			printf("%d\n", numbers[i].number);
		}
	}

	return 0;
}
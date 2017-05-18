#include <stdio.h>
#include <stdlib.h>

#define MAX_MAKERS 10000
#define MAX_PRICE 1000001

int arr[MAX_PRICE];

void init_price()
{
	int i;
	for (i = 0; i < MAX_PRICE; i++)
		arr[i] = -1;
}

void update_arr(int min, int max, int index)
{
	int i;
	for (i = min; i <= max; i++)
	{
		if (arr[i] == -1)
			arr[i] = index;
		else if (arr[i] >= 0)
			arr[i] = -2;
	}
}

typedef struct
{
	char company[25];
	int low, high;
}car_maker;
car_maker car_makers[MAX_MAKERS];

int sortf(const void *a, const void *b)
{
	car_maker *cm1 = (car_maker *)a;
	car_maker *cm2 = (car_maker *)b;
	if (cm1->high == cm1->high)
		return cm1->low - cm2->low;
	else
		return cm1->high - cm2->high;
}

int getindex(int price, int N)
{
	int i, index = -1;
	for (i = 0; i < N; i++)
	{
		if (price >= car_makers[i].low && price <= car_makers[i].high)
		{
			if (index >= 0)
				return -1;
			index = i;
		}
	}
	return index;
}


int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T, i, D, Q, index, p;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &D);
		for (i = 0; i < D; i++)
		{
			scanf("%s %d %d", &car_makers[i].company, &car_makers[i].low, &car_makers[i].high);
		}

		qsort(car_makers, D, sizeof(car_maker), sortf);

		scanf("%d", &Q);
		for (i = 0; i < Q; i++)
		{
			scanf("%d", &p);
			index = getindex(p, D);
			if (index < 0)
				printf("UNDETERMINED\n");
			else
				puts(car_makers[index].company);
		}
		if (T)
			printf("\n");
	}
}
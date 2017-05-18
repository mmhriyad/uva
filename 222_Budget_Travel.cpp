#include <stdio.h>
#include <math.h>

typedef struct
{
	double distance, pricepp;
}t_station;

t_station stations[50];

int N;

double gas_capacity, mpg, distance, min_cost;

void backtrack(int st, double dist, double gas, double cost)
{
	if (st == N || dist == distance)
	{
		//cost
		if (min_cost > cost)
			min_cost = cost;
		//printf("cost %lf\n", cost);
		return;
	}
	int i;
	double next_dist;
	//for (i = st; i < N; ++i)
	{
		if (st + 1 == N)
			next_dist = distance - dist;
		else
			next_dist = stations[st + 1].distance - dist;

		if ((gas * mpg < next_dist) || (gas <= gas_capacity / 2))
		{
			double station_cost = ((gas_capacity - gas) * stations[st].pricepp) / 100 + 2;
			station_cost *= 100;
			station_cost = round(station_cost);
			station_cost /= 100;
			backtrack(st + 1, dist + next_dist, gas_capacity - (next_dist / mpg), cost + station_cost);
		}
		if (gas * mpg >= next_dist)
			backtrack(st + 1, dist + next_dist, gas - (next_dist / mpg), cost);
		//backtrack(st + 1, dist, gas, cost);
	}
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	double init_cost;
	int cn = 0, i;
	while (scanf("%lf", &distance) == 1)
	{
		if (distance < 0)
			break;
		++cn;
		scanf("%lf %lf %lf %d", &gas_capacity, &mpg, &init_cost, &N);
		for (i = 0; i < N; ++i)
			scanf("%lf %lf", &stations[i].distance, &stations[i].pricepp);
		printf("Data Set #%d\n", cn);
		min_cost = 1 << 31 - 1;
		backtrack(0, stations[0].distance, gas_capacity - (stations[0].distance / mpg), init_cost);
		printf("minimum cost = $%.2lf\n", min_cost);
	}
	return 0;
}
#include <stdio.h>

#define MAX_ORDER 22
#define MAX_STN	7

typedef struct
{
	int nOrder;
	int order[MAX_ORDER][2];
}station_t;

station_t stations[MAX_STN];

int NStn, NOrd, Cap;

void init()
{
	int i, j;
	for (i = 0; i < MAX_STN; ++i)
	{
		stations[i].nOrder = 0;
	}
}

int N = 5, arr[5];
bool taken[10];

void backtrack(int index)
{
	int i;
	if (index == N)
	{
		for (i = 0; i < N; ++i)
		{
			printf("%d", arr[i]);
		}
		printf("\n");
		return;
	}

	for (i = 9; i >=0; --i)
	{
		if (!(i == 0 && index == 0))
		{
			taken[i] = true;
			arr[index] = i;
			backtrack(index + 1);
			taken[i] = false;
		}
	}

}

int main()
{
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int i, j;
	int s, d, p;
	//while (scanf("%d %d %d", &Cap, &NStn, &NOrd) == 3)
	//{
	//	if (Cap == 0 && NStn == 0 && NOrd == 0)
	//		return 0;
	//	init();
	//	for (i = 0; i < NOrd; ++i)
	//	{
	//		scanf("%d %d %d", &s, &d, &p);
	//		stations[s].order[stations[s].nOrder][0] = d;
	//		stations[s].order[stations[s].nOrder][1] = p;
	//		++stations[s].nOrder;
	//	}
	//}
	backtrack(0);
	return 0;
}
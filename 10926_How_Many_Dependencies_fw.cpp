#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTASK 101
#define INF 999999

int N = MAXTASK;

typedef struct
{
	int taskid;
	int dird;
	int indird;
	int total;
	bool processed;
	int dependson[MAXTASK];
}task;

task t[MAXTASK];

int arr[MAXTASK][MAXTASK];

void init()
{
	int i, j;
	for(i=0; i<N; i++)
	{
		t[i].taskid = i+1;
		t[i].dird = 0;
		t[i].indird = 0;
		t[i].total = 0;
		t[i].processed = false;
	}

	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			arr[i][j] = INF;
		}
		arr[i][i] = 0;
	}
}

int sortf(const void *a, const void *b)
{
	task *t1 = (task *)b;
	task *t2 = (task *)a;

	if((t1->dird + t1->indird) == (t2->dird + t2->indird))
		return t2->taskid - t1->taskid;
	return ((t1->dird + t1->indird) - (t2->dird + t2->indird));
}

void fw()
{
	int i, j, k;
	for(k=0; k<N; k++)
	{
		for(i=0; i<N; i++)
		{
			for(j=0; j<N; j++)
			{
				if(arr[i][j] > arr[i][k] + arr[k][j])
				{
					if(arr[i][j] == INF)
					{
						t[i].indird++;
					}
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
	int i, j, a;
	while((scanf("%d", &N) == 1) && N)
	{
		init();
		for(i=0; i<N; i++)
		{
			scanf("%d", &t[i].dird);
			for(j=0; j<t[i].dird; j++)
			{
				scanf("%d", &a);
				t[i].dependson[j] = a-1;
				arr[i][a-1] = 1;
			}
		}
		fw();
		qsort(t, N, sizeof(task), sortf);

		printf("%d\n", t[0].taskid);

		/*for(i=0; i<N; i++)
		{
			printf("task [%d]-> [%d + %d]\n", t[i].taskid, t[i].dird, t[i].indird);
		}*/

	}
	return 0;
}
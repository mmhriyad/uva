#include <stdio.h>
#include <stdlib.h>

#define MAXTASK 101

int N;

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

void init()
{
	int i;
	for(i=0; i<N; i++)
	{
		t[i].taskid = i+1;
		t[i].dird = 0;
		t[i].indird = 0;
		t[i].total = 0;
		t[i].processed = false;
	}
}

int getindir(int in)
{
	int j, i;
	if(t[in].dird == 0)
	{
		t[in].processed = true;
		return 0;
	}
	for(j=0; j<t[in].dird; j++)
	{
		i = t[in].dependson[j]-1;

		if(!t[i].processed)
			t[in].indird += getindir(i);
		else if(t[in].indird)
			t[in].indird--;
	}
	t[in].processed = true;
	return t[in].dird + t[in].indird;
}


void calcindir()
{
	int i, j, k;

	for(i=0; i<N; i++)
	{
		if(!t[i].processed)
		{
			for(j=0; j<t[i].dird; j++)
			{
				k = t[i].dependson[j] - 1;
				if(!t[k].processed)
					t[i].indird += getindir(t[i].dependson[j] - 1);
				else if(t[i].indird>0)
					t[i].indird--;
			}
		}
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

int main()
{
	//freopen("input.txt", "r", stdin);
	int i, j;
	while((scanf("%d", &N) == 1) && N)
	{
		init();
		for(i=0; i<N; i++)
		{
			scanf("%d", &t[i].dird);
			for(j=0; j<t[i].dird; j++)
			{
				scanf("%d", &t[i].dependson[j]);
			}
		}
		calcindir();
		qsort(t, N, sizeof(task), sortf);

		printf("%d\n", t[0].taskid);

	}
	return 0;
}
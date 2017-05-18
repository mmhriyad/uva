#include <stdio.h>
#define MAXN 13

int arr[MAXN];
int K;
int per[6] = {0, 1, 2, 3, 4, 5};
bool finished = false;

void increase(int index)
{
	if(index < 0)
	{
		finished = true;
		return;
	}
	per[index]++;
	if(index >= 0 && per[index] >= (K - (5-index)))
	{
		increase(index-1);
		per[index] = per[index-1]+1;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	int i, caseno = 0;
	while(scanf("%d", &K) == 1 && K)
	{
		for(i=0; i<K; i++)
		{
			scanf("%d", &arr[i]);

			if(i<6)
				per[i] = i;
		}
		finished = false;
		if(caseno>0)
			printf("\n");
		while(!finished)
		{
			printf("%d %d %d %d %d %d\n", arr[per[0]], arr[per[1]], arr[per[2]], arr[per[3]], arr[per[4]], arr[per[5]]);
			increase(5);
		}
		caseno++;
	}
	return 0;
}
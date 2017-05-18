#include <stdio.h>

#define MAXP 1000001

int pl[MAXP], s_l[101];

int T, P, D, SL;

int main()
{
	freopen("input.txt", "r", stdin);
	int i, a, b;
	bool end = false;
	scanf("%d", &T);
	while(T--)
	{
		end = false;
		for(i=0; i<101; i++)
			s_l[i] = i;
		scanf("%d %d %d", &P, &SL, &D);
		for(i=0; i<P; i++)
			pl[i] = 1;
		for(i=0; i<SL; i++)
		{
			scanf("%d %d", &a, &b);
			s_l[a] = b;
		}
		for(i=0; i<D; i++)
		{
			scanf("%d", &a);
			if(!end)
			{
				b = i%P;
				pl[b] += a;
				if(pl[b] > 100)
					pl[b] = 100;
				pl[b] = s_l[pl[b]];
				if(pl[b] >=100)
				{
					pl[b] = 100;
					end = true;
				}
			}
		}

		for(i=0; i<P; i++)
		{
			printf("Position of player %d is %d.\n", i+1, pl[i]);
		}
	}
}
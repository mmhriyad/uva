/*
12376_As_Long_as_I_Learn_I_Live.cpp
Author : Md. Mahbubul Huq
*/
#include <stdio.h>

#define MAXN 100
#define MAXE 5001

int w[MAXN], next[MAXN], N, E, max, max_node;


void init(void)
{
	int i;
	for (i = 0; i < N; i++)
	{
		next[i] = i;
	}
}

int main()
{
	int T, i, cn, s, d;
	freopen("input.txt", "r", stdin);

	scanf("%d", &T);
	for (cn = 1; cn <= T; cn++)
	{
		scanf("%d %d", &N, &E);
		init();
		for (i = 0; i < N; i++)
			scanf("%d", &w[i]);
		for (i = 0; i < E; i++)
		{
			scanf("%d %d", &s, &d);
			if(next[s] == s || w[next[s]] < w[d])
				next[s] = d;
		}
		
		s = 0;
		max = w[s];
		max_node = s;
		while(next[s] != s)
		{
			max += w[next[s]];
			max_node = s = next[s];
		}

		printf("Case %d: %d %d\n", cn, max, max_node);
	}

	return 0;
}

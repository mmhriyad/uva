// time limit exceed
#include <stdio.h>

#define MAXN 100000

typedef struct
{
	char substr[11];
	bool visited;
	int count;
}t_node;

t_node nodes[MAXN];

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int i, N, j, k, NS;
	int max_count, max_index;
	char inp[2*MAXN];
	
	while (scanf("%d %s", &N, &inp) == 2)
	{
		i = 0;
		NS = 0;
		max_count = 0;
		/*
		N = 0;
		while (inp[i] >= '0' && inp[i] <= '9')
		{
			N = N * 10 + inp[i] - '0';
			++i;
		}
		while (!(inp[i] >= 'a' && inp[i] <= 'z'))
			++i;
			*/
		while (inp[i])
		{
			for (j = i, k = 0; inp[j] && k < N; ++j, ++k)
			{
				nodes[NS].substr[k] = inp[j];
			}
			if (k < N)
				break;
			nodes[NS].substr[k] = 0x00;
			nodes[NS].count = 1;
			nodes[NS].visited = false;
			++NS;
			++i;
		}

		for (i = 0; i < NS-1; ++i)
		{
			if (!nodes[i].visited)
			{
				nodes[i].visited = true;
				for (j = i + 1; j < NS; ++j)
				{
					k = 0;
					while (k < N && (nodes[i].substr[k] == nodes[j].substr[k]))
					{
						++k;
					}
					if (k == N)
					{
						++nodes[i].count;
						nodes[j].visited = true;
					}
				}

				if (nodes[i].count > max_count)
				{
					max_count = nodes[i].count;
					max_index = i;
				}
			}
		}// end for

		puts(nodes[max_index].substr);
	}
}
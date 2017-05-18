#include "stdio.h"
#include "math.h"

#define MAX 1005
#define MAXVAL 200000

int n, r, states;
int points[MAX][2], taken_following_nodes[MAX];
double graph[MAX][MAX], min_edges[MAX];
double total_rail, total_roads;
bool taken[MAX];
int g_parent = -1, g_child = -1 ;
double g_min = MAXVAL;

void update_nodes(int parent, int child)
{
	bool found_min = false;
	int min_node = -1, i, j;
	double min = MAXVAL;

	if(parent >= 0)
	{
		i = parent;
		min = MAXVAL;
		min_node = -1;
		for(j=0; j<n; j++)
		{
			if(graph[i][j]>0 && graph[i][j]<min && taken[j] == false)
			{
				min_node = j;
				min = graph[i][j];
			}
		}
		if(min < MAXVAL)
		{
			min_edges[i] = min;
			taken_following_nodes[i] = min_node;
			if(min <= g_min)
			{
				g_min = min;
				g_child = min_node;
				g_parent = i;
				found_min = true;
			}
		}
		else
		{
			min_edges[i] = -1;
			taken_following_nodes[i] = -1;
		}
	}

	if(child >= 0)
	{
		i = child;
		min = MAXVAL;
		min_node = -1;
		for(j=0; j<n; j++)
		{
			if(graph[i][j]>0 && graph[i][j]<min && taken[j] == false)
			{
				min_node = j;
				min = graph[i][j];
			}
		}
		if(min < MAXVAL)
		{
			min_edges[i] = min;
			taken_following_nodes[i] = min_node;

			if(min <= g_min)
			{
				g_min = min;
				g_child = min_node;
				g_parent = i;
				found_min = true;
			}
		}
		else
		{
			min_edges[i] = -1;
			taken_following_nodes[i] = -1;
		}
	}

	if(found_min == false)
	{
		//printf("if(found_min == false), g_min=%f, g_child=%d\n", g_min, g_child);
		g_min = MAXVAL;
		g_child = -1;
		for(i=0; i<n; i++)
		{
			if(taken[i])
			{
				min_node = -1;
				min = MAXVAL;
				for(j=0; j<n; j++)
				{
					if(graph[i][j]>0 && graph[i][j]<min && taken[j] == false)
					{
						min_node = j;
						min = graph[i][j];
					}
				}
				if(min < MAXVAL)
				{
					min_edges[i] = min;
					taken_following_nodes[i] = min_node;

					if(min <= g_min)
					{
						g_min = min;
						g_child = min_node;
						g_parent = i;
					}
				}
				else
				{
					min_edges[i] = -1;
					taken_following_nodes[i] = -1;
				}
			}
		}
	}
}

void countnshow()
{
	int taken_count, i, j;
	taken_count = 1;
	taken[0] = true;
	states = 1;
	total_rail = total_roads = 0;

	g_min = MAXVAL;
	g_child = -1;
	g_parent = 0;

	//double min;
	while(taken_count < n)
	{
		update_nodes(g_parent, g_child);
		
		if(g_min < MAXVAL)
		{
			//printf("%d, ", (int)g_min); //remove this
			taken_count++;
			taken[g_child] = true;

			if(g_min>r)
			{
				total_rail += g_min;
				states++;
			}
			else total_roads += g_min;
			graph[g_parent][g_child] = graph[g_child][g_parent] = 0;
		}
	}

	printf("%d %d %d", states, (int)(total_roads+0.5), (int)(total_rail+0.5));
}

int main()
{
	int T, i;
	scanf("%d", &T);
	//printf("%d\n", T);
	///*
	for(i=1; i<=T; i++)
	{
		
		int j, k, a, b, c;
		scanf("%d %d", &n, &r);
		states = total_rail = total_roads = 0;
		///*
		for(j=0; j<n; j++)
		{
			scanf("%d %d", &a, &b);
			points[j][0] = a;
			points[j][1] = b;
			taken[j] = false;
			min_edges[j] = -1;
			taken_following_nodes[j] = -1;
			graph[j][j] = 0;
			for(k=j-1;k>=0;k--)
			{
				graph[k][j] = graph[j][k] = (hypot((double)(points[j][0]-points[k][0]), (double)(points[j][1]-points[k][1])));
			}
		}
		//*/
		//cut these codes start
		/*
		for(j=0; j<n; j++)
		{
			taken[j] = false;
			min_edges[j] = -1;
			taken_following_nodes[j] = -1;
			graph[j][j] = 0;
		}
		for(j=0; j<r; j++)
		{
			scanf("%d %d %d", &a, &b, &c);
			graph[a][b] = graph[b][a] = c;
			//taken[j] = false;			
		}
		*/
		//cut these codes end
		printf("Case #%d: ", i);
		countnshow();
		printf("\n");
	}
	//*/
	return 0;
}
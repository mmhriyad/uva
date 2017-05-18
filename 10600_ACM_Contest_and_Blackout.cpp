#include "stdio.h"
#include "math.h"
#include <iostream>
#include <vector>
using namespace std;

#define MAX 1005
#define MAXVAL 200000

int n, r, states;
//int taken_following_nodes[MAX];
int graph[MAX][MAX], min_edges[MAX], graph_tmp[MAX][MAX];
int total_rail, total_roads;
bool taken[MAX];
int g_parent = -1, g_child = -1 ;
int g_min = MAXVAL;

vector<pair<int, pair<int, int>>> mst_edges, graph_edges;

void update_nodes(int parent, int child)
{
	bool found_min = false;
	int min_node = -1, i, j;
	int min = MAXVAL;

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
			//taken_following_nodes[i] = min_node;
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
			//taken_following_nodes[i] = -1;
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
			//taken_following_nodes[i] = min_node;

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
			//taken_following_nodes[i] = -1;
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
					//taken_following_nodes[i] = min_node;

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
					//taken_following_nodes[i] = -1;
				}
			}
		}
	}
}

int countnshow(bool first_mst)
{
	int taken_count, i, j, mst_cost;
	taken_count = 1;
	taken[0] = true;
	states = 1;
	total_rail = total_roads = 0;

	g_min = MAXVAL;
	g_child = -1;
	g_parent = 0;
	mst_cost = 0;

	while(taken_count < n)
	{
		update_nodes(g_parent, g_child);
		
		if(g_min < MAXVAL)
		{
			//printf("%d, ", (int)g_min); //remove this
			taken_count++;
			taken[g_child] = true;

			mst_cost += g_min;
			if(first_mst)
				mst_edges.push_back(make_pair(g_min, make_pair(g_parent, g_child)));

			graph[g_parent][g_child] = graph[g_child][g_parent] = 0;
		}
		else
		{
			mst_cost = MAXVAL;
			break;
		}
	}

	//printf("%d", mst_cost);
	return mst_cost;
}

int main()
{
	int T, i;
	scanf("%d", &T);
	//printf("%d\n", T);
	
	for(i=1; i<=T; i++)
	{
		
		int j, k, a, b, c;
		mst_edges.clear();
		graph_edges.clear();
		scanf("%d %d", &n, &r);
		states = total_rail = total_roads = 0;
		
		
		for(j=0; j<n; j++)
		{
			taken[j] = false;
			min_edges[j] = -1;
			//taken_following_nodes[j] = -1;
			for(k=0; k<n; k++)
				graph[j][k] = 0;
		}
		for(j=0; j<r; j++)
		{
			scanf("%d %d %d", &a, &b, &c);
			graph_edges.push_back(make_pair(c, make_pair(a-1, b-1)));
			graph[a-1][b-1] = graph[b-1][a-1] = c;
			graph_tmp[a-1][b-1] = graph_tmp[b-1][a-1] = c;
		}
		
		int first_mst_cost, second_mst_cost, mst_cost;
		first_mst_cost = countnshow(true);
		second_mst_cost = MAXVAL;

		for(k=0; k<mst_edges.size(); k++)
		{
			for(j=0; (j<n || j<r); j++)
			{
				if(j<n)
				{
					taken[j] = false;
					min_edges[j] = -1;
					//taken_following_nodes[j] = -1;
				}
				if(j<r)
				{
					graph[graph_edges[j].second.first][graph_edges[j].second.second] = 
					graph[graph_edges[j].second.second][graph_edges[j].second.first] = graph_edges[j].first;
					
				}
			}

			graph[mst_edges[k].second.first][mst_edges[k].second.second] = 
					graph[mst_edges[k].second.second][mst_edges[k].second.first] = 0;

			mst_cost = countnshow(false);
			if(mst_cost < second_mst_cost)
			{
				second_mst_cost = mst_cost;
			}
			if(second_mst_cost == first_mst_cost) break;

			graph[mst_edges[k].second.first][mst_edges[k].second.second] = 
					graph[mst_edges[k].second.second][mst_edges[k].second.first] = mst_edges[k].first;


		}
		
		//printf("Case #%d: ", i);
		printf("%d %d\n", first_mst_cost, second_mst_cost);
		
		//printf("\n");
	}

	return 0;
}
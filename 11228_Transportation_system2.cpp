//using set
#include "stdio.h"
#include "math.h"
#include <iostream>
#include <set>
using namespace std;

#define MAX 1005
#define MAXVAL 200000

int n, r, states;
int points[MAX][2], taken_following_nodes[MAX];
double graph[MAX][MAX], min_edges[MAX];
double total_rail, total_roads;
bool taken[MAX];
int g_parent = -1, g_child = -1 ;
double g_min = MAXVAL;

//pair<distance, child>
set<pair<double, int>> set_graph[MAX];
set<pair<double, int>>::iterator it_node;
//pair<pair<distance, child>, parent>
set<pair<pair<double, int>, int>> set_taken_nodes;
set<pair<pair<double, int>, int>>::iterator it_taken_node;

void countnshow()
{
	int taken_count, i, j;
	set_taken_nodes.clear();
	states = 1;
	total_rail = total_roads = 0;

	g_min = MAXVAL;
	g_child = -1;
	g_parent = 0;

	taken_count = 1;
	taken[0] = true;
	if(!set_graph[0].empty())
	{
		it_node = set_graph[0].begin();
		set_taken_nodes.insert(make_pair( make_pair(it_node->first, it_node->second), 0));
		set_graph[it_node->second].erase(set_graph[it_node->second].find(make_pair(it_node->first, 0)));
		set_graph[0].erase(it_node);
	}
	
	
	
	while(taken_count < n)
	{
		//update_nodes(g_parent, g_child);
		bool added = false;
		while(!added)
		{
			it_taken_node = set_taken_nodes.begin();
			g_min = it_taken_node->first.first;
			g_child = it_taken_node->first.second;
			g_parent = it_taken_node->second;
			if(taken[g_child])
			{
				set_taken_nodes.erase(it_taken_node);
				added = false;
				while(!added && !set_graph[g_parent].empty())
				{
					it_node = set_graph[g_parent].begin();
					if(it_node != set_graph[g_parent].end())
					{
						if(!taken[it_node->second])
						{
							//if(set_taken_nodes.find(make_pair( make_pair(it_node->first, g_parent ), it_node->second)) == set_taken_nodes.end()) //not exist
							set_taken_nodes.insert(make_pair( make_pair(it_node->first, it_node->second), g_parent));
							added = true;
						}
						set_graph[it_node->second].erase(set_graph[it_node->second].find(make_pair(it_node->first, g_parent)));
						set_graph[g_parent].erase(it_node);
					}
				}

				added = false;
			}
			else
				added = true;
		}
		//printf("%d, ", (int)g_min);
		//if(g_min < MAXVAL)
		{
			taken_count++;
			taken[g_child] = true;

			if(g_min>r)
			{
				total_rail += g_min;
				states++;
			}
			else total_roads += g_min;
			//graph[g_parent][g_child] = graph[g_child][g_parent] = 0;

			
		}

		if(taken_count < n)
		{

			set_taken_nodes.erase(it_taken_node);
			added = false;
			while(!added && !set_graph[g_parent].empty())
			{
				it_node = set_graph[g_parent].begin();
				if(it_node != set_graph[g_parent].end())
				{
					if(!taken[it_node->second])
					{
						//if(set_taken_nodes.find(make_pair( make_pair(it_node->first, g_parent ), it_node->second)) == set_taken_nodes.end()) //not exist
						set_taken_nodes.insert(make_pair( make_pair(it_node->first, it_node->second), g_parent));
						added = true;
					}
					set_graph[it_node->second].erase(set_graph[it_node->second].find(make_pair(it_node->first, g_parent)));
					set_graph[g_parent].erase(it_node);
				}
			}

			added = false;

			while(!added && !set_graph[g_child].empty())
			{
				it_node = set_graph[g_child].begin();
				if(it_node != set_graph[g_child].end())
				{
					if(!taken[it_node->second])
					{
						//if(set_taken_nodes.find(make_pair( make_pair(it_node->first, g_child ), it_node->second)) == set_taken_nodes.end()) //not exist
						set_taken_nodes.insert(make_pair( make_pair(it_node->first, it_node->second), g_child));
						added = true;
					}
					set_graph[it_node->second].erase(set_graph[it_node->second].find(make_pair(it_node->first, g_child)));
					set_graph[g_child].erase(it_node);
				}
			}

		}
	}

	printf("%d %d %d", states, (int)(total_roads+0.5), (int)(total_rail+0.5));
}

int main()
{
	int T, i;
	double dist;
	scanf("%d", &T);
	
	for(i=1; i<=T; i++)
	{
		
		int j, k, a, b, c;
		scanf("%d %d", &n, &r);
		states = total_rail = total_roads = 0;

		for(j=0; j<n; j++)
			set_graph[j].clear();
		///*
		for(j=0; j<n; j++)
		{
			
			scanf("%d %d", &a, &b);
			points[j][0] = a;
			points[j][1] = b;
			taken[j] = false;
			//min_edges[j] = -1;
			//taken_following_nodes[j] = -1;
			//graph[j][j] = 0;
			for(k=j-1;k>=0;k--)
			{
				dist = (hypot((double)(points[j][0]-points[k][0]), (double)(points[j][1]-points[k][1])));
				//graph[k][j] = graph[j][k] = distance;
				set_graph[k].insert(make_pair(dist, j));
				set_graph[j].insert(make_pair(dist, k));
			}
		}
		//*/
		//cut these codes start
		/*
		
		for(j=0; j<r; j++)
		{
			scanf("%d %d %d", &a, &b, &c);
			//graph[a][b] = graph[b][a] = c;
			set_graph[a].insert(make_pair(c, b));
			set_graph[b].insert(make_pair(c, a));
			//taken[j] = false;			
		}
		*/
		//cut these codes end
		
		
		printf("Case #%d: ", i);
		countnshow();
		printf("\n");
	}
	
	return 0;
}
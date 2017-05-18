//using set
#include "stdio.h"
#include "math.h"
#include <iostream>
#include <vector>
#include <algorithm>
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
vector<pair<double, int>> vec_graph[MAX];
vector<pair<double, int>>::iterator it_node;
//pair<pair<distance, child>, parent>
vector<pair<pair<double, int>, int>> vec_taken_nodes;
vector<pair<pair<double, int>, int>>::iterator it_taken_node;

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

	for(i=0;i<n;i++)
	{
		sort(vec_graph[i].begin(), vec_graph[i].end());
	}

	if(!vec_graph[0].empty())
	{
		it_node = vex_graph[0].begin();
		vec_taken_nodes.push_back(make_pair( make_pair(it_node->first, it_node->second), 0));
		vec_graph[it_node->second].erase(vec_graph[it_node->second].find(make_pair(it_node->first, 0)));
		vec_graph[0].erase(it_node);
	}
	
	
	
	while(taken_count < n)
	{
		//update_nodes(g_parent, g_child);
		bool added = false;
		while(!added)
		{
			it_taken_node = vec_taken_nodes.begin();
			g_min = it_taken_node->first.first;
			g_child = it_taken_node->first.second;
			g_parent = it_taken_node->second;
			if(taken[g_child])
			{
				vec_taken_nodes.erase(it_taken_node);
				added = false;
				while(!added && !vec_graph[g_parent].empty())
				{
					it_node = vec_graph[g_parent].begin();
					if(it_node != vec_graph[g_parent].end())
					{
						if(!taken[it_node->second])
						{
							//if(set_taken_nodes.find(make_pair( make_pair(it_node->first, g_parent ), it_node->second)) == set_taken_nodes.end()) //not exist
							vec_taken_nodes.push_back(make_pair( make_pair(it_node->first, it_node->second), g_parent));
							added = true;
						}
						vec_graph[it_node->second].erase(set_graph[it_node->second].find(make_pair(it_node->first, g_parent)));
						vec_graph[g_parent].erase(it_node);
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

			vec_taken_nodes.erase(it_taken_node);
			added = false;
			while(!added && !vec_graph[g_parent].empty())
			{
				it_node = vec_graph[g_parent].begin();
				if(it_node != vec_graph[g_parent].end())
				{
					if(!taken[it_node->second])
					{
						//if(set_taken_nodes.find(make_pair( make_pair(it_node->first, g_parent ), it_node->second)) == set_taken_nodes.end()) //not exist
						vec_taken_nodes.push_back(make_pair( make_pair(it_node->first, it_node->second), g_parent));
						added = true;
					}
					vec_graph[it_node->second].erase(set_graph[it_node->second].find(make_pair(it_node->first, g_parent)));
					vec_graph[g_parent].erase(it_node);
				}
			}

			added = false;

			while(!added && !vec_graph[g_child].empty())
			{
				it_node = vec_graph[g_child].begin();
				if(it_node != vec_graph[g_child].end())
				{
					if(!taken[it_node->second])
					{
						//if(set_taken_nodes.find(make_pair( make_pair(it_node->first, g_child ), it_node->second)) == set_taken_nodes.end()) //not exist
						vec_taken_nodes.push_back(make_pair( make_pair(it_node->first, it_node->second), g_child));
						added = true;
					}
					vec_graph[it_node->second].erase(vec_graph[it_node->second].find(make_pair(it_node->first, g_child)));
					vec_graph[g_child].erase(it_node);
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
			vec_graph[j].clear();
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
				vec_graph[k].push_back(make_pair(dist, j));
				vec_graph[j].push_back(make_pair(dist, k));
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
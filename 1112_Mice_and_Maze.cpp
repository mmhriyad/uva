//using dijkstra
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_NODE 105
#define MAX_VAL 999999999

vector<pair<int, int>> vec_edges[MAX_NODE]; //first item is for wight, second is node index
vector<pair<int, int>>::iterator it_vec;
vector<pair<int, int>> vec_queue, *cur_node; //first item for weight, second is node index

bool taken_nodes[MAX_NODE];
int dist[MAX_NODE];
int parent[MAX_NODE];
int T, N, E, M, Tm;

int getNextNode()
{
	int min = MAX_VAL, min_node = -1, i;
	for(i=1;i<=N;i++)
	{
		if(!taken_nodes[i])
		{
			if(dist[i] != -1 && dist[i] < min)
			{
				min_node = i;
				min = dist[i];
			}
		}
	}
	return min_node;
}

int process_and_coutn()
{
	int count, cur_node, i;
	dist[E] = 0;
	count = 0;
	
	while(count < N-1)
	{
		cur_node = getNextNode();
		for(it_vec = vec_edges[cur_node].begin(); it_vec != vec_edges[cur_node].end(); ++it_vec)
		{
			if(dist[it_vec->second] == -1 || ((dist[it_vec->second] > dist[cur_node] + it_vec->first) && !taken_nodes[it_vec->second]))
			{
				dist[it_vec->second] = dist[cur_node] + it_vec->first;
				//vec_queue.push_back(make_pair(dist[it_vec->second],it_vec->second));
			}
		}
		taken_nodes[cur_node] = true;
		count++;
	}
	count = 0;
	for(i=1; i<=N; i++)
	{
		if(dist[i]<=Tm)
			count++;
	}
	return count;
}

int main()
{
	int i, a, b, c;
	cin>>T;
	while(T)
	{
		for(i=0;i<MAX_NODE;i++)
		{
			vec_edges[i].clear();
			taken_nodes[i]=false;
			dist[i] = MAX_VAL;
			parent[i] = -1;
		}
		cin>>N>>E>>Tm>>M;

		for(i=0;i<M;i++)
		{
			cin>>a>>b>>c;
			//vec_edges[a].push_back(make_pair(c, b));
			vec_edges[b].push_back(make_pair(c, a));
		}
		cout<<process_and_coutn()<<endl;
		T--;
		if(T)
			cout<<endl;

	}
	return 0;
}

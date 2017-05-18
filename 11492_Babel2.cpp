#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

#define MAX_NODES 4002
#define INF 1e6

struct edge
{
	int to;
	int length;
	int fchar;

	bool operator<(const edge &other) const
    {
        return length > other.length;
    }
};

map<string, int> nodes;
vector<edge> edgelist[MAX_NODES];
priority_queue<edge> pq;

int dist[MAX_NODES][27];

int getID(string s)
{
	if(nodes.find(s) == nodes.end())
		nodes[s] = nodes.size();
	return nodes[s];
}

int main()
{
	
	int M, i, j, u, v;
	edge e;
	string src,	dstn, a, b, word;

	for(;;)
	{
		cin>>M;
		if(M==0) return 0;

		for(i=0;i<nodes.size();i++)
		{
			edgelist[i].clear();
		}
		nodes.clear();

		cin>>src>>dstn;

		for(i=0;i<M;i++)
		{
			cin>>a>>b>>word;
			u = getID(a);
			v = getID(b);
			e.fchar = word[0]-'a';
			e.length = word.length();
			e.to = v;
			edgelist[u].push_back(e);
			e.to = u;
			edgelist[v].push_back(e);
		}

		
		if((nodes.find(src) == nodes.end() || nodes.find(dstn) == nodes.end()) || (getID(src) == getID(dstn)))
		{
			cout<<"impossivel"<<endl;
			continue;
		}

		for(i=0;i<nodes.size();i++)
		{
			for(j=0; j<27; j++)
			{
				dist[i][j] = INF;
			}
		}

		u = getID(src);
		for(j=0; j<27; j++)
		{
			dist[u][j] = 0;
		}
		e.fchar = 26;
		e.length = 0;
		e.to = u;
		pq.push(e);
		while(!pq.empty())
		{
			e = pq.top();
			pq.pop();
			for(i=0; i<edgelist[e.to].size(); i++)
			{
				edge l = edgelist[e.to][i];
				if((l.fchar != e.fchar) && (dist[l.to][l.fchar] > dist[e.to][e.fchar] + l.length))
				{
					dist[l.to][l.fchar] = dist[e.to][e.fchar] + l.length;
					pq.push(l);
				}
				
			}
		}

		v = getID(dstn);
		int min = dist[v][0];

		for(j=1;j<27;j++)
		{
			if(min>dist[v][j])
				min = dist[v][j];
		}

		if(min == INF)
			cout<<"impossivel"<<endl;
		else 
			cout<<min<<endl;

		
	}
	return 0;
}

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_NODES 101
#define NINF -99999999

int n, pow[MAX_NODES], dist[MAX_NODES];
vector<int> edges[MAX_NODES];
vector<pair<int,int>> all_edges;
queue<int> q;
bool visited[MAX_NODES], visited2[MAX_NODES];

bool reached = false, cycle = false, died = false;
int cycle_index = 0;

void isReachable(int node)
{
	visited2[node] = true;
	if(node == n)
	{
		reached = true;
		return;
	}
	for(int i=0;i<edges[node].size();i++)
	{
		if(reached)
			break;
		if(!visited2[edges[node][i]])
			isReachable(edges[node][i]);
		if(reached)
			break;
	}

}

void dfs(int energy, int u)
{

	if(u == n)
	{
		if(pow[u]+energy > 0 && !died)
		{
			reached = true;
		}
		else if(cycle)
		{
			for(int i=1; i<=n; i++)
				visited2[i] = false;
			
			isReachable(cycle_index);
		}
	}
	else
	{
		dist[u] = energy;
		visited[u] = true;
		for(int i=0;i<edges[u].size();i++)
		{
			int v = edges[u][i];

			//if(pow[v]+energy > 0 && !visited[v])//dist[v] < pow[v]+energy)
			if(dist[v] < pow[v]+energy)// && !visited[v])
			{
				if(!visited[v])
				{
					if(pow[v]+energy <= 0)
						died = true;
					dfs(pow[v]+energy, v);
				}
				else
				{
					if(!died)
					{
						cycle = true;
						cycle_index = v;
					}
				}
				if(reached)
					break;
			}
		}
	}
}

bool bellmanford()
{
	for(int i=1;i<=n;i++)
		dist[i] = NINF;

	dist[1] = 100;
	for(int i=1; i<=n; i++)
	{
		for(int j=0; j<all_edges.size(); j++)
		{
			pair<int,int> e = all_edges[j];
			if(dist[e.second] < pow[e.second] + dist[e.first] && pow[e.second] + dist[e.first] > 0)
			{
				dist[e.second] = pow[e.second] + dist[e.first];
				if(e.second == n && dist[e.second] > 0)
					return true;
			}
		}
	}
	
	//if(dist[n] == NINF)
		return false;
	//if(dist[n] > 0)
	//	return true;
	/*
	for(int j=0; j<all_edges.size(); j++)
	{
		pair<int,int> e = all_edges[j];
		if(dist[e.second] < pow[e.second] + dist[e.first])// && dist[n] < 0) //can power-up
		{
			dist[e.second] = pow[e.second] + dist[e.first];
			if(e.second == n)
				return true;
		}
	}

	return false;
	*/
/*
	for(int i=2; i<n; i++)
	{
		if(dist[i]<=dist[i-1] && dist[i]<=dist[i+1])
			return false;
	}
	return true;
	*/
}

void floyd_warshal()
{
	int dist2[MAX_NODES][MAX_NODES];
	int i,j,k;
	bool has_cycle = false;
	for(i=1; i<=n;i++)
		for(j=1;j<=n;j++)
			dist2[i][j] = NINF;
	for(i=1; i<=n; i++)
		dist2[i][i] = 0;
	for(j=0; j<all_edges.size(); j++)
	{
		pair<int,int> e = all_edges[j];
		dist2[e.first][e.second] = pow[e.second];

		if(e.first == 1)
			dist2[e.first][e.second] += 100;
	}
	for(k=1; k<=n; k++)
	{
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				if((dist2[i][j] < dist2[i][k]+dist2[k][j]) && (dist2[i][k]+dist2[k][j] > 0))
				{
					if(dist2[i][j] > 0)
						has_cycle = true;
					dist2[i][j] = dist2[i][k]+dist2[k][j];
				}
			}
		}
	}
	if(dist2[1][n]>0 || has_cycle)
		cout<<"winnable"<<endl;
	else
		cout<<"hopeless"<<endl;
 }

int main()
{
	int i,m,p,e;
	for(;;)
	{
		cin>>n;
		if(n == -1) return 0;
		all_edges.clear();
		for(i=1;i<=n;i++)
		{
			edges[i].clear();
			dist[i] = NINF;//0;
			visited[i] = false;

			cin>>p>>m;

			pow[i] = p;

			while(m)
			{
				cin>>e;
				edges[i].push_back(e);
				all_edges.push_back(make_pair(i,e));
				m--;
			}
		}
		if(n == 1)
			cout<<"winnable"<<endl;
		else
		{
			reached = cycle = died = false;
			//floyd_warshal();
			cycle_index = 0;
			dfs(100, 1);
			if(reached)
				cout<<"winnable"<<endl;
			else
				cout<<"hopeless"<<endl;
			/*
			dfs(100, 1);
			if(1)//bellmanford()) //reached)
				cout<<"winnable"<<endl;
			else
				cout<<"hopeless"<<endl;
				*/
		}
	}
	return 0;
}

/*
sameple input:
5
0 1 2
20 1 3
-70 1 4
-80 1 5
0 0
5
0 1 2
21 1 3
-60 1 4
-60 1 5
0 0
5
0 1 2
-60 1 3
-60 1 4
20 1 5
0 0
5
0 1 2
20 2 1 3
-60 1 4
-60 1 5
0 0
5
0 1 2
-60 1 3
-60 1 3
100 1 5
0 0
7
0 1 2
-90 1 3
-90 1 4
100 1 5
100 1 6
100 3 1 4 7
0 0
-1

samsple output:
hopeless
winnable
hopeless
winnable
hopeless
hopeless

7
0 1 2
-90 1 3
-90 1 4
100 1 5
100 1 6
100 3 1 4 7
0 0
5
0 1 2
20 2 1 3
-60 1 4
-60 1 5
0 0
7
0 1 2
-98 2 3 5
-1 1 4
101 1 1
-60 1 6
-60 1 7
0 0
7
0 2 2 6
-60 1 3
100 1 4
100 1 5
100 1 2
-120 1 7
0 0

hopeless
winnable
winnable
hopeless
*/
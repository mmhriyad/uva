#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_NODES 105

#define INF 99999999
#define NINF -INF

#define GET_SUM(x,y) ((x==INF || y==INF) ? INF : (x+y))

int n;

vector<int> adj_edge[MAX_NODES];
int room_pow[MAX_NODES], dist[MAX_NODES];

bool finished[MAX_NODES], discovered[MAX_NODES], reached = false;

void dfs(int energy, int u)
{
    int v;
    discovered[u] = true;
    for(int j=0; j<adj_edge[u].size(); j++)
    {
        v = adj_edge[u][j];
        if(dist[v] < GET_SUM(energy, room_pow[v]) && GET_SUM(energy, room_pow[v]) > 0)
        {
            dist[v] = ( (discovered[v] && !finished[v]) ? INF : GET_SUM(energy, room_pow[v]));
            if(v == n)
			{
                reached = true;
				break;
			}
			dfs(dist[v], v);
        }
		if(reached)
			break;
    }
	finished[u] = true;
}

int main()
{
    int i,j,k, e, nc, m;
    for(;;)
    {
        cin>>n;
        if(n == -1)
            return 0;

        for(i=1; i<=n; i++)
        {
            dist[i] = NINF;
			finished[i] = discovered[i] = false;
            cin>>e>>nc;
            room_pow[i] = e;
            adj_edge[i].clear();
            while(nc--)
            {
                cin>>m;
                adj_edge[i].push_back(m);
            }
        }

        if(n==1)
            cout<<"winnable"<<endl;
        else
		{
			reached = false;
			dist[1] = 0;
			dfs(100, 1);
			if(reached)
				cout<<"winnable"<<endl;
			else
				cout<<"hopeless"<<endl;
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
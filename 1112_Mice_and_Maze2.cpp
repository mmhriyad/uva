//floyd-warshal
#include <iostream>
using namespace std;

#define MAX_NODE 105
#define MAX_VAL 9999999

int graph[MAX_NODE][MAX_NODE], dist[MAX_NODE][MAX_NODE];
int T, N, E, M, Tm;

int main()
{
	int i, j, k, a, b, c;
	cin>>T;
	while(T)
	{
		cin>>N>>E>>Tm>>M;

		for(i=1;i<=N;i++)
		{
			for(j=1;j<=N;j++)
			{
				if(i == j)
					dist[i][j] = 0;
				else
					dist[i][j] = MAX_VAL;
			}
		}

		for(i=0;i<M;i++)
		{
			cin>>a>>b>>c;
			dist[a][b] = c;
		}

		for(k=1; k<=N; k++)
		{
			for(i=1; i<=N; i++)
			{
				for(j=1; j<=N; j++)
				{
					if(dist[i][j] > dist[i][k]+dist[k][j])
						dist[i][j] = dist[i][k]+dist[k][j];
				}
			}
		}
		int node_count = 0;
		for(i=1;i<=N;i++)
		{
			if(dist[i][E] <= Tm)
				node_count++;

		}
		cout<<node_count<<endl;
		T--;
		if(T)
			cout<<endl;
	}
	return 0;
}

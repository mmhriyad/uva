#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

#define MAX 10005

vector <int> nodes[MAX];
bool fallen[MAX];

int n,m,l, T, count = 0;

void dfs(int s)
{
	int i, size = nodes[s].size();
	if(!fallen[s])
	{
		count++;
		fallen[s] = true;
		for(i=0; i<size; i++)
			if(!fallen[nodes[s][i]])
				dfs(nodes[s][i]);
	}
}


int main()
{
	freopen("input.txt", "r", stdin);
	int i, j, a, b;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d %d", &n, &m, &l);

		for(i=0; i<=n; i++)
		{
			fallen[i] = false;
			nodes[i].clear();
		}

		for(i=0; i<m; i++)
		{
			scanf("%d %d", &a, &b);
			nodes[a].push_back(b);
		}
		count = 0;
		for(i=0; i<l; i++)
		{
			scanf("%d", &a);
			
			if(!fallen[a])
			{
				dfs(a);
			}
		}
		printf("%d\n", count);

	}
}
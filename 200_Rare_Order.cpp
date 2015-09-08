/*
200_Rare_Order.cpp
Author : Md. Mahbubul Huq (Riyad)
*/
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

bool taken[26], visited[26], arr[26][26];
vector<char> vec;

int adjlist[26][27];

void toposort(int u)
{
	int v, l, i;
	visited[u] = true;
	l = adjlist[u][0];
	for(i=1; i<=l; i++)
	{
		v = adjlist[u][i];
		if(v >= 0 && !visited[v])
			toposort(v);
	}
	vec.push_back(u+'A');
}

void init()
{
	int i, j;
	for(i=0; i<26; i++)
	{
		visited[i] = taken[i] = false;
		adjlist[i][0] = 0;
		for(j = 0; j<26; j++)
			arr[i][j] = false;
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	char inp[30], prev[30];
	int i, j, n = 0, u, v;
	init();
	while(gets(inp))
	{
		if(inp[0] == '#')
		{
			for(i=0; i<26; i++)
			{
				if(taken[i] && !visited[i])
					toposort(i);
			}

			while(!vec.empty())
			{
				printf("%c", vec.back());
				vec.pop_back();
			}
			printf("\n");
			init();
			n = 0;
			continue;
		}
		n++;
		if(n == 1)
		{
			strcpy(prev, inp);
			i = 0;
			while(inp[i])
			{
				taken[inp[i] - 'A'] = true;
				i++;
			}
		}
		else
		{
			i = 0;
			while(inp[i])
			{
				taken[inp[i] - 'A'] = true;
				i++;
			}

			i = j = 0;
			while(inp[i] && prev[j] && inp[i] == prev[j])
			{
				i++;
				j++;
			}
			
			if(inp[i] && prev[j])
			{
				//next[prev[j] - 'A'] = inp[i] - 'A';
				u = prev[j] - 'A';
				v = inp[i] - 'A';
				if(!arr[u][v])
				{
					adjlist[u][ ++adjlist[u][0] ] = v;
					arr[u][v] = true;
				}
			}

			strcpy(prev, inp);
		}
	}

	
	return 0;
}

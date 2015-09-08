/*
929_Number_Maze.cpp
Author : Md. Mahbubul Huq (Riyad)
*/
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

#define MAXN 1001
#define INF (1<<30)

int arr[MAXN][MAXN], tmp[MAXN][MAXN];
int N, M;
bool visited[MAXN*MAXN], added[MAXN*MAXN];;

typedef struct
{
	int i,j;
}node;

queue<node> q[10];

int dir[4][2] = {{-1,0}, {1,0}, {0, -1}, {0, 1}};

void run_maze(int x, int y)
{
	int i, j, k;
	static int count = 0;
	node na;

	while(x >= 0 && y >= 0)
	{
		visited[x*M + y] = true;

		for(k=0; k<4; k++)
		{
			i = x + dir[k][0];
			j = y + dir[k][1];
			if(i<N && i>=0 && j<M && j>=0)
			{
				if(!visited[i*M+j] && (tmp[i][j] > arr[i][j] + tmp[x][y]))
				{
					tmp[i][j] = arr[i][j] + tmp[x][y];
					if(!added[i*M+j])
					{
						na.i = i;
						na.j = j;
						q[tmp[i][j]%10].push(na);
						added[i*M+j] = true;
					}
				}
			}
		}

		node na_min;
		int min_k = 0, min_cost = INF;

		for(k=0; k<10; k++)
		{
			if(!q[k].empty())
			{
				na = q[k].front();
				if(tmp[na.i][na.j] < min_cost)
				{
					min_k = k;
					min_cost = tmp[na.i][na.j];
					na_min.i = na.i;
					na_min.j = na.j;
				}
			}
			if(min_cost == 0)
				break;
		}

		if(min_cost != INF)
		{
			i = na_min.i;
			j = na_min.j;
			if(i == N-1 && j == M-1)
				return;
			q[min_k].pop();
			x = i;
			y = j;
		}
		else
		{
			x = y = -1;
		}
	}

}

int main()
{
	//freopen("input.txt", "r", stdin);
	int i, j, T, k;
	char inp[MAXN*3];
	scanf("%d", &T);
	while(T--)
	{
		for(i=0; i<10; i++)
		{
			while(!q[i].empty())
				q[i].pop();
		}
		scanf("%d %d", &N, &M);
		gets(inp);
		for(i=0; i<N; i++)
		{
			gets(inp);
			j = k = 0;
			while(1)
			{
				tmp[i][j] = INF;
				visited[i*M + j] = added[i*M + j] = false;
				arr[i][j++] = (inp[k] - '0');
				if(i > 0)
				{
					if(tmp[i][j] > arr[i][j] + tmp[i-1][j])
						tmp[i][j] = arr[i][j] + tmp[i-1][j];
				}
				if(j > 0)
				{
					if(tmp[i][j] > arr[i][j] + tmp[i][j-1])
						tmp[i][j] = arr[i][j] + tmp[i][j-1];
				}

				if(!inp[k+1])
					break;
				k += 2;
				
			}
		}
		tmp[0][0] = arr[0][0];
		run_maze(0, 0);

		printf("%d\n", tmp[N-1][M-1]);

	}
	return 0;
}

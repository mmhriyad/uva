#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char maps[31][81],c;
int  smap[31][81],n;
int dx[]={-1,1,0,0},dy[]={0,0,-1,1};

const char space = ' ', endlc = '_', wall = 'X';
void dfs(int x, int y)
{
	int i;
	if (x<0 || x>=n || y<0 ||smap[x][y] || maps[x][y] == wall)
		return;
	maps[x][y] = c;
	smap[x][y] = 1;
	for(i=0;i<4;i++)
		dfs(x+dx[i],y+dy[i]);
}

int main()
{
	freopen("input.txt","r",stdin);
	int count = 0;
	while (gets(maps[count])) {
		while (maps[count][0] != endlc) 
			gets(maps[++count]);
		n=count;
		memset(smap, 0, sizeof(smap));
		for (int i = 0; i < count; ++ i)
		{
			for (int j = 0; maps[i][j]; ++ j)
			{
				if (maps[i][j] != space && maps[i][j] != wall)
				{
					c=maps[i][j];
					dfs(i, j);
				}
			}
		}
		
		for (int i = 0; i <= count; ++ i)
			puts(maps[i]);
		
		count = 0;
	}
    return 0;
}

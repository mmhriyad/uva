#include <stdio.h>
#define MAXN 101
int T, m, n, count=0, sum=0;
char arr[MAXN][MAXN];

void find(int i, int j)
{
	if(arr[i][j] == '@')
	{
		sum++;
		arr[i][j] = '0';
	}
	if((i-1>=0 && j-1>=0) && (arr[i-1][j-1] == '@'))
		find(i-1, j-1);
	if(i-1>=0 && arr[i-1][j] == '@')
		find(i-1, j);
	if((i-1>=0 && j+1<n) && (arr[i-1][j+1] == '@'))
		find(i-1, j+1);

	if(j-1>=0 && arr[i][j-1] == '@')
		find(i, j-1);
	if(j+1<n && arr[i][j+1] == '@')
		find(i, j+1);

	if((i+1<m && j-1>=0) && (arr[i+1][j-1] == '@'))
		find(i+1, j-1);
	if(i+1<m && arr[i+1][j] == '@')
		find(i+1, j);
	if((i+1<m && j+1<n) && (arr[i+1][j+1] == '@'))
		find(i+1, j+1);
}

int main()
{
	freopen("input.txt", "r", stdin);
	int i, j;
	for(;;)
	{
		scanf("%d %d", &m, &n);
		if(m == 0 && n == 0)
			return 0;
		for(i=0; i<m; i++)
			scanf("%s", &arr[i]);
		count = 0;
		for(i=0; i<m; i++)
		{
			for(j=0; j<n; j++)
			{
				if(arr[i][j] == '@')
				{
					find(i, j);
					count++;
				}
			}
		}
		printf("%d\n", count);
	}
}
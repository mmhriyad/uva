#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

char arr[MAX][MAX], arr2[MAX][MAX];
int m, n, count;

void getcount(int i, int j)
{
	if(arr2[i][j] == 'W')
	{
		count++;
		arr2[i][j] = '0';
	}
	if((i-1 >=0 && j-1>=0) && arr2[i-1][j-1] == 'W')
		getcount(i-1, j-1);
	if(i-1>=0 && arr2[i-1][j] == 'W')
		getcount(i-1, j);
	if((i-1>=0 && j+1<m) && arr2[i-1][j+1] == 'W')
		getcount(i-1, j+1);

	if(j-1>=0 && arr2[i][j-1] == 'W')
		getcount(i, j-1);
	if(j+1<m && arr2[i][j+1] == 'W')
		getcount(i, j+1);

	if((i+1<n && j-1>=0) && arr[i+1][j-1] == 'W')
		getcount(i+1, j-1);
	if((i+1<n) && arr2[i+1][j] == 'W')
		getcount(i+1, j);
	if((i+1<n && j+1<m) && arr2[i+1][j+1] == 'W')
		getcount(i+1, j+1);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int T, i, j, x, y;
	scanf("%d", &T);
	while(T--)
	{
		for(i=0; i<MAX; i++)
		{
			scanf("%s", &arr[i]);
			if(arr[i][0] >= '1' && arr[i][0] <= '9')
				break;
		}
		n = i;
		m = strlen(arr[0]);

		x = atoi(arr[i]);
		scanf("%d", &y);

		for(i=0; i<n; i++)
			strcpy(arr2[i], arr[i]);

		count = 0;
		if((x-1<n && y-1<m) && (arr[x-1][y-1] == 'W'))
			getcount(x-1, y-1);
		printf("%d\n", count);

		while(scanf("%d %d", &x, &y) == 2)
		{
			for(i=0; i<n; i++)
			strcpy(arr2[i], arr[i]);

			count = 0;
			if((x-1<n && y-1<m) && (arr[x-1][y-1] == 'W'))
				getcount(x-1, y-1);
			printf("%d\n", count);
		}
		if(T)
			printf("\n");
	}

}
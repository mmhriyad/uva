#include <stdio.h>

#define MAX 201

char arr[MAX][MAX];
int n;

bool reached = false;

bool bwin(int i, int j)
{
	arr[i][j] = '0';
	if(i == n-1)
	{
		reached = true;
		return reached;
	}
	if(!reached && i-1 >=0 && arr[i-1][j] == 'b')
		bwin(i-1, j);
	if(!reached && (i-1 >=0 && j-1>=0) && (arr[i-1][j-1] == 'b'))
		bwin(i-1, j-1);
	if(!reached && j-1 >=0 && arr[i][j-1] == 'b')
		bwin(i, j-1);
	if(!reached && j+1<n && arr[i][j+1] == 'b')
		bwin(i, j+1);
	if(!reached && i+1<n && arr[i+1][j] == 'b')
		bwin(i+1, j);
	if(!reached && (i+1<n && j+1<n) && arr[i+1][j+1] == 'b')
		bwin(i+1, j+1);

	return reached;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int i, j, caseno=1;
	for(;;)
	{
		scanf("%d", &n);
		if(n == 0)
			return 0;
		for(i=0; i<n; i++)
			scanf("%s", &arr[i]);
		reached = false;
		for(i=0; i<n; i++)
		{
			if(arr[0][i] == 'b')
				reached = bwin(0, i);
			if(reached)
				break;
		}
		printf("%d ", caseno++);
		if(reached)
			printf("B\n");
		else
			printf("W\n");

	}
}
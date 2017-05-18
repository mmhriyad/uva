#include <stdio.h>

#define MAXN 101

char arr[MAXN][MAXN];

int dir[8][2] = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};

int M, N;

char bomb = '*', dot = '.';

void fill(int x, int y)
{
	int i, a, b;

	for(i=0; i<8; i++)
	{
		a = x + dir[i][0];
		b = y + dir[i][1];
		if((a>=0 && a<M) && (b>=0 && b<N) && arr[a][b] != bomb)
		{
			if(arr[a][b] == dot)
				arr[a][b] = '0';
			arr[a][b]++;
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	int i, j, fno = 1;
	char ch;
	while(scanf("%d %d", &M, &N) == 2)
	{
		if(M == 0 && N == 0)
			return 0;
		for(i=0; i<M; i++)
		{
			scanf("%s", &arr[i]);
		}

		for(i=0; i<M; i++)
		{
			for(j=0; j<N; j++)
			{
				if(arr[i][j] == bomb)
					fill(i,j);
				else if(arr[i][j] == dot)
					arr[i][j] = '0';
			}
		}
		if(fno>1)
			printf("\n");
		printf("Field #%d:\n", fno++);
		for(i=0; i<M; i++)
			printf("%s\n", arr[i]);
	}

}
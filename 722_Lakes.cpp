/*
722_Lakes.cpp
Author : Md. Mahbubul Huq (Riyad)
*/
#include <stdio.h>
#include <string.h>

#define MAXN 200

char arr[MAXN][MAXN];

int M, N, wx, wy, count;

int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

void getCount(int x, int y)
{
	int i, nx, ny;
	count++;
	arr[x][y] = '-';
	for (i = 0; i < 4; i++)
	{
		nx = x + dir[i][0];
		ny = y + dir[i][1];
		if ((nx >= 0 && nx < N && ny >= 0 && ny < M) && arr[nx][ny] == '0')
			getCount(nx, ny);
	}
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &wx, &wy);
		N = M = 0;
		gets(arr[0]);
		while (gets(arr[N]) && arr[N][0])
		{
			N++;
		}
		M = strlen(arr[0]);
		count = 0;
		getCount(wx-1, wy-1);
		printf("%d\n", count);
		if (T)
			printf("\n");
	}

	return 0;
}
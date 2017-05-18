#include <stdio.h>
#define MAXN 101
int T, m, n, count=0, sum=0;
char arr[MAXN][MAXN];

const char ch = 'X';
const char dice = '*';

int num[7] = {0,};

void findnum(int i, int j)
{
	if(arr[i][j] == ch)
	{
		arr[i][j] = dice;//'0';
	}
	//if((i-1>=0 && j-1>=0) && (arr[i-1][j-1] == ch))
	//	findnum(i-1, j-1);
	if(i-1>=0 && arr[i-1][j] == ch)
		findnum(i-1, j);
	//if((i-1>=0 && j+1<n) && (arr[i-1][j+1] == ch))
	//	findnum(i-1, j+1);

	if(j-1>=0 && arr[i][j-1] == ch)
		findnum(i, j-1);
	if(j+1<n && arr[i][j+1] == ch)
		findnum(i, j+1);

	//if((i+1<m && j-1>=0) && (arr[i+1][j-1] == ch))
	//	findnum(i+1, j-1);
	if(i+1<m && arr[i+1][j] == ch)
		findnum(i+1, j);
	//if((i+1<m && j+1<n) && (arr[i+1][j+1] == ch))
	//	findnum(i+1, j+1);
}

void find(int i, int j, bool fromx = false)
{
	if(arr[i][j] == dice)
	{
		arr[i][j] = '0';
	}
	/*if(i-1>=0 && j-1>=0)
	{
		if(arr[i-1][j-1] == dice)
			find(i-1, j-1);
		else if(!fromx && arr[i-1][j-1] == ch)
		{
			sum++;
			findnum(i-1, j-1);
			arr[i-1][j-1] = dice;
			find(i-1, j-1, true);
		}
	}*/
	if(i-1>=0)
	{
		if(arr[i-1][j] == dice)
			find(i-1, j);
		else if(arr[i-1][j] == ch)
		{
			sum++;
			findnum(i-1, j);
			arr[i-1][j] = dice;
			find(i-1, j, true);
		}
	}
	/*if(i-1>=0 && j+1<n)
	{
		if(arr[i-1][j+1] == dice)
			find(i-1, j+1);
		else if(!fromx && arr[i-1][j+1] == ch)
		{
			sum++;
			findnum(i-1, j+1);
			arr[i-1][j+1] = dice;
			find(i-1, j+1, true);
		}
	}*/
	if(j-1>=0)
	{
		if(arr[i][j-1] == dice)
			find(i, j-1);
		else if(arr[i][j-1] == ch)
		{
			sum++;
			findnum(i, j-1);
			arr[i][j-1] = dice;
			find(i, j-1, true);
		}
	}
	if(j+1<n)
	{
		if(arr[i][j+1] == dice)
			find(i, j+1);
		else if(arr[i][j+1] == ch)
		{
			sum++;
			findnum(i, j+1);
			arr[i][j+1] = dice;
			find(i, j+1, true);
		}
	}
	/*if(i+1<m && j-1>=0)
	{
		if(arr[i+1][j-1] == dice)
			find(i+1, j-1);
		else if(!fromx && arr[i+1][j-1] == ch)
		{
			sum++;
			findnum(i+1, j-1);
			arr[i+1][j-1] = dice;
			find(i+1, j-1, true);
		}
	}*/
	if(i+1<m)
	{
		if(arr[i+1][j] == dice)
			find(i+1, j);
		else if(arr[i+1][j] == ch)
		{
			sum++;
			findnum(i+1, j);
			arr[i+1][j] = dice;
			find(i+1, j, true);
		}
	}
	/*if(i+1<m && j+1<n)
	{
		if(arr[i+1][j+1] == dice)
			find(i+1, j+1);
		else if(!fromx && arr[i+1][j+1] == ch)
		{
			sum++;
			findnum(i+1, j+1);
			arr[i+1][j+1] = dice;
			find(i+1, j+1, true);
		}
	}*/
}

int main()
{
	freopen("input.txt", "r", stdin);
	int i, j, T=1;
	for(;;)
	{
		scanf("%d %d", &n, &m);
		if(m == 0 && n == 0)
			return 0;
		for(i=0; i<7; i++)
			num[i] = 0;

		for(i=0; i<m; i++)
			scanf("%s", &arr[i]);
		
		for(i=0; i<m; i++)
		{
			for(j=0; j<n; j++)
			{
				if(arr[i][j] == dice)
				{
					sum = 0;
					find(i, j);
					num[sum]++;
				}
			}
		}
		for(i=0; i<m; i++)
		{
			for(j=0; j<n; j++)
			{
				if(arr[i][j] == ch)
				{
					findnum(i, j);
					num[1]++;
				}
			}
		}
		printf("Throw %d\n", T++);
		sum = 0;
		for(i=1; i<7; i++)
		{
			if(num[i])
			{
				for(j=0; j<num[i]; j++)
				{
					if(sum)
						printf(" ");
					printf("%d", i);
					sum++;
				}
			}
		}
		if(sum == 0)
			printf("0");
		printf("\n\n");
	}
}
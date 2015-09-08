/*
10113_Exchange_Rates.cpp
Author : Md. Mahbubul Huq (Riyad)
*/
#include <stdio.h>
#include <string.h>

#define MAXNAMEL 25
#define MAXN 61

char items[MAXN][MAXNAMEL];
int N;
int arr[MAXN][MAXN];

int find(char *name, bool insert)
{
	int i;
	for(i=0; i<N; i++)
		if(0 == strcmp(items[i], name))
			return i;
	if(insert)
		strcpy(items[N++], name);
	return i;
}

int gcd(int a, int b)
{
	int c;
	if(a < b)
	{
		c = a;
		a = b;
		b = c;
	}
	while(b != 0)
	{
		c = a%b;
		a = b;
		b = c;
	}
	return a;
}

void run_fw()
{
	int i, j, k, a, b, g;
	for(k=0; k<N; k++)
	{
		for(i=0; i<N; i++)
		{
			for(j=0; j<N; j++)
			{
				if(0 == arr[i][j] && arr[i][k]>0 && arr[k][j] > 0)
				{
					arr[i][j] = a = arr[i][k] * arr[k][j];
					arr[j][i] = b = arr[j][k] * arr[k][i];
					g = gcd(a, b);
					if(g > 1)
					{
						arr[i][j] /= g;
						arr[j][i] /= g;
					}
				}
			}
		}
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
	memset(arr, 0, sizeof(arr));
	char c, item1[MAXNAMEL], item2[MAXNAMEL];
	int a, b, g, i, j;
	bool need_update = false;
	while(1)
	{
		c = getchar();
		if(c == '.')
			break;
		getchar(); //take the space
		if(c == '!') // input
		{
			scanf("%d %s = %d %s", &a, &item1, &b, &item2);
			g = gcd(a, b);
			a /= g;
			b /= g;
			i = find(item1, true);
			j = find(item2, true);
			arr[i][j] = a;
			arr[j][i] = b;
			need_update = true;
		}
		else if(c == '?') // query
		{
			scanf("%s = %s", &item1, &item2);
			
			if(need_update)
			{
				run_fw();
				need_update = false;
			}

			i = find(item1, false);
			j = find(item2, false);
			
			if(arr[i][j] == 0)
			{
				printf("? %s = ? %s\n", item1, item2);
			}
			else
			{
				printf("%d %s = %d %s\n", arr[i][j], item1, arr[j][i], item2);
			}
		}
		getchar();
	}
	return 0;
}

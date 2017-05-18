#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXS 51

typedef struct
{
	char state;
	int count;
}state;

state s[MAXS*MAXS];

char arr[MAXS][MAXS], filled = '.';

int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

int N, H, W;

int count = 0;

int comp(const void *a, const void *b)
{
	state *s1 = (state*)a;
	state *s2 = (state*)b;

	if(s1->count == s2->count)
		return (s1->state - s2->state);
	return (s2->count - s1->count);
}

void fill(int x, int y, char ch)
{
	if(arr[x][y] == ch)
	{
		count++;
		arr[x][y] = filled;
	}
	int i, a, b;
	for(i=0; i<4; i++)
	{
		a = x + dir[i][0];
		b = y + dir[i][1];

		if((a>=0 && a<H) && (b>=0 && b<W) && (arr[a][b] == ch))
			fill(a, b, ch);
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int i, j, T, found = 0;
	//scanf("%d", &N);
	T = 1;
	while(scanf("%d %d", &H, &W) == 2 && H && W)
	{
		for(i=0; i<H; i++)
			scanf("%s", &arr[i]);

		printf("Problem %d:\n", T++);
		found = 0;
		for(i=0; i<H; i++)
		{
			for(j=0; j<W; j++)
			{
				if(arr[i][j] != filled)
				{
					count = 0;
					char ch = arr[i][j];
					fill(i, j, ch);
					s[found].count = count;
					s[found].state = ch;
					found++;
				}
			}
		}

		qsort(s, found, sizeof(state), comp);
		
		for(i=0; i<found; i++)
		{
			if(s[i].count > 0)
				printf("%c %d\n", s[i].state, s[i].count);
		}
	}
}


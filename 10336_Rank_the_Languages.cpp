#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXS 1024

typedef struct
{
	char state;
	int count;
}state;

state s[26];

char arr[MAXS][MAXS], filled = '-';

int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

int N, H, W;

int count = 0;

int comp(const void *a, const void *b)
{
	state *s1 = (state*)a;
	state *s2 = (state*)b;
	//printf("%c=%d, %c=%d\n", s1->state, s1->count, s2->state, s2->count);
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
void init()
{
	int i;
	for(i=0; i<26; i++)
	{
		s[i].state = 'a' + i;
		s[i].count = 0;
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	int i, j, T;
	scanf("%d", &N);
	
	for(T=1; T<=N; T++)
	{
		scanf("%d %d", &H, &W);

		for(i=0; i<H; i++)
			scanf("%s", &arr[i]);

		init();
		printf("World #%d\n", T);

		for(i=0; i<H; i++)
		{
			for(j=0; j<W; j++)
			{
				if(arr[i][j] != filled)
				{
					count = 0;
					char ch = arr[i][j];
					fill(i, j, ch);
					s[ch-'a'].count++; 
				}
			}
		}

		qsort(s, 26, sizeof(state), comp);
		
		for(i=0; i<26; i++)
		{
			if(s[i].count > 0)
				printf("%c: %d\n", s[i].state, s[i].count);
		}
	}
}


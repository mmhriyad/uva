/*
12582 - Wedding of Sultan
Author : Md. Mahbubul Huq
*/
#include <stdio.h>

#define MAXN 26

int arr[MAXN], count = 0;
char stack[MAXN];

void push(char a)
{
	stack[count++] = a;
}

char pop()
{
	char a = 0;
	if(count > 0)
		a = stack[count--];
	return a;
}

char top()
{
	return stack[count-1];
}

void init()
{
	int i;
	for(i=0; i<MAXN; i++)
	{
		arr[i] = 0;
	}
	count = 0;
}

int main()
{
	//freopen("input.txt" , "r", stdin);
	int T, cn, i;
	char inp[1000], ch;
	scanf("%d", &T);
	gets(inp);
	for(cn = 1; cn <= T; cn++)
	{
		gets(inp);
		init();
		printf("Case %d\n", cn);
		i = 0;
		while(inp[i])
		{
			ch = top();
			if(ch != inp[i])
			{
				if(ch)
				{
					arr[ch - 'A']++;
					arr[inp[i] - 'A']++;
				}
				push(inp[i]);
			}
			else
			{
				pop();
			}
			i++;
		}//end while

		for(i=0; i<MAXN; i++)
		{
			if(arr[i] > 0)
				printf("%c = %d\n", (i+'A'), arr[i]);
		}
	}
	return 0;
}

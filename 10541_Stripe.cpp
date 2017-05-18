#include "stdio.h"
#include "string.h"

#define MAXLEN 210

char arr[MAXLEN][MAXLEN][MAXLEN]; //for pascal's triangle
char inp1[MAXLEN] = "999";
char inp2[MAXLEN] = "1";

void add(char *num1, char *num2)
{
	char tmp[MAXLEN] = {0,};
	int len1, len2, i, j;
	char ch;
	bool carry=false;
	int num;
	
	if(strlen(num1) < strlen(num2))
	{
		strcpy(tmp, num1);
		strcpy(num1, num2);
		strcpy(num2, tmp);
	}

	len1 = strlen(num1);
	len2 = strlen(num2);

	for(i=0, j=0; (len1)&&(len2); i++, j++, len1--, len2--)
	{
		num = (num1[i]-'0') + (num2[j]-'0');
		num += carry;
		ch = ((num)%10)+'0';
		num1[i] = ch;

		if(num > 9)
			carry = true;
		else
			carry = false;
	}
	i = strlen(num1) - len1;
	
	while(carry)
	{
		if(i == strlen(num1))
		{
			num1[i] = '0';
			num1[i+1] = 0x00;
		}
		num = (num1[i]-'0');
		num += carry;
		ch = ((num)%10)+'0';
		num1[i++] = ch;

		if(num > 9)
			carry = true;
		else
			carry = false;
	}
}

int main()
{
	int T, N, K, K_all, i, j, l, m, inp, empty, extra;

	int a, b;

	int max_line = MAXLEN;

	for(i=0; i<MAXLEN; i++)
	{
		strncpy(arr[i][0], "1", 1);
		strncpy(arr[i][i], "1", 1);
	}
	//building pascal's triangle
	for(i=2; i<max_line; i++)
	{
		for(j=1; j<i; j++)
		{
			strcpy(inp1, arr[i-1][j-1]);
			strcpy(inp2, arr[i-1][j]);
			add(inp1, inp2);
			strcpy(arr[i][j], inp1);
		}
	}
	
	scanf("%d",&T);
	for(i=0; i<T; i++)
	{
		scanf("%d %d", &N, &K);
		
		if(K==0)
			printf("1\n");
		else
		{
			K_all=0; inp=0;
			for(j=0; j<K; j++)
			{
				scanf("%d",&inp);
				K_all += inp;
			}

			extra = K_all - K;
			empty = K-1;
				
			a = N-extra-empty;
			b = K;
			if(a<b)
				printf("0\n");
			else
			{
				strcpy(inp1, arr[a][b]);
				l = strlen(inp1);
				for(l=strlen(inp1)-1; l>=0; l--)
				{
					printf("%c", inp1[l]);
				}
				
				printf("\n");
			}
		}
	}
	return 0;
}

/*
sample input:
==================
6 
200 50 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
5 2 1 2 
4 0 
4 2 2 2 
200 25 1 2 3 1 2 5 6 4 8 2 1 4 2 1 4 2 1 4 2 1 5 2 1 3 2 
25 5 2 3 2 8 1 
====================

sample output:
====================
30093344528411106697329459321983432455140
3
1
0
587784321942209843029001280
252
*/
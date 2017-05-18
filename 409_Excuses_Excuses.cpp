#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NL '\n'
#define MAXWORD 25
#define MAXSENT 75

int nw, ne;

typedef struct
{
	int len;
	char wrd[MAXWORD];
}word;
word w[MAXWORD];

typedef struct
{
	int total_words;
	int max;
	char wrds[MAXWORD][MAXSENT];
	char sents[MAXSENT];
}excuse;
excuse exs[MAXWORD];

int sortf(const void *a, const void *b)
{
	char *c1 = (char *)a;
	char *c2 = (char *)b;
	return strcmp(c1, c2);
}

bool findmatch(char *a)
{
	int len = strlen(a);
	int i, j;
	for(i=0; i<nw; i++)
	{
		if(w[i].len > len)
			return false;
		if(len == w[i].len)
		{
			for(j=0; a[j] && w[i].wrd[j]; j++)
			{
				if(a[j] != w[i].wrd[j])
					break;
			}
			if(!a[j])
				return true;
		}
	}
	return false;
}

int main()
{
	freopen("input.txt", "r", stdin);

	int i, j, k, l, max, caseno = 1;
	
	while(scanf("%d %d", &nw, &ne) == 2)
	{
		max = 0;
		for(i=0; i<nw; i++)
		{
			scanf("%s", w[i].wrd);
			w[i].len = strlen(w[i].wrd);
		}
		qsort(w, nw, sizeof(word), sortf);

		char ch;
		ch = getchar();
		for(i=0; i<ne; i++)
		{
			j = -1;
			k = 0;
			l = 0;
			exs[i].total_words = 0;
			exs[i].max = 0;
			for(;;)
			{
				ch = getchar();
				exs[i].sents[l++] = ch;
				if(ch == NL || ch == EOF)
				{
					if(ch == EOF)
						exs[i].sents[l-1] = 0x00;
					if(k>0)
						exs[i].wrds[j][k] = 0x00;
					break;
				}
				else if(ch == ' ' || ch == '"' || ch == '.' || ch == ',' || ch == '!' || ch == '?' || ch == '&')
				{
					if(k>0)
						exs[i].wrds[j][k] = 0x00;
					k = 0;
				}
				else if((ch >= 'A' && ch <='Z') || (ch >= 'a' && ch <= 'z'))
				{
					if(k == 0)
					{
						j++;
						exs[i].total_words++;
					}
					if(ch >= 'A' && ch <='Z')
						ch = ch - 'A' + 'a';
					exs[i].wrds[j][k++] = ch;
				}
			}

			for(j=0; j<exs[i].total_words; j++)
			{
				exs[i].max += findmatch(exs[i].wrds[j]);
			}
			if(max < exs[i].max)
				max = exs[i].max;
		}
		printf("Excuse Set #%d\n", caseno++);
		for(i=0; i<ne; i++)
		{
			if(max == exs[i].max)
				printf("%s", exs[i].sents);
		}
		printf("\n");
	}
}
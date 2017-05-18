#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXL 205

typedef struct
{
	int id;
	bool dupli;
	char str[MAXL];
}t_word;

t_word dictionary[100000];

int sortf(const void *a, const void *b)
{
	int ret;
	t_word *word1 = (t_word *)a;
	t_word *word2 = (t_word *)b;
	ret = strcmp(word1->str, word2->str);
	if (!ret)
	{
		if (word1->id > word2->id)
			word1->dupli = true;
		else
			word2->dupli = true;
	}
	return ret;
}

int main()
{
	/*freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	char inp[MAXL], ch;
	
	int i, n, k;
	n = 0;
	while (gets(inp))
	{
		i = 0;
		while (inp[i])
		{
			while (inp[i] && !((inp[i] >= 'a' && inp[i] <= 'z') || (inp[i] >= 'A' && inp[i] <= 'Z')))
				++i;
			k = 0;
			while (inp[i])
			{
				ch = inp[i];
				if (ch >= 'a' && ch <= 'z')
					dictionary[n].str[k++] = ch;
				else if (ch >= 'A' && ch <= 'Z')
					dictionary[n].str[k++] = ch + 'a' - 'A';
				else
					break;
				++i;
			}
			dictionary[n].str[k] = 0x00;
			if (k > 0)
			{
				dictionary[n].id = n;
				dictionary[n].dupli = false;
				++n;
			}
		}
	}

	qsort(dictionary, n, sizeof(t_word), sortf);

	for (i = 0; i < n; ++i)
	{
		if (!dictionary[i].dupli)
			puts(dictionary[i].str);
	}
	
}
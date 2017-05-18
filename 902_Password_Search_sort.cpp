#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 1000000

char inp[MAXN], substr[MAXN][12], pass[12];

int sortf(const void *a, const void *b)
{
	char *str1 = (char *)a;
	char *str2 = (char *)b;

	return strcmp(str1, str2);
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int size, len, i, max, j, k, max_index, count;
	while (scanf("%d %s", &size, &inp) == 2)
	{
		len = strlen(inp);
		len -= size;
		
		for (i = 0; i <= len; ++i)
		{
			for (j = i, k = 0; k < size; ++j, ++k)
			{
				substr[i][k] = inp[j];
			}
			substr[i][k] = 0x00;
		}
		for (j = 0; j <=  size; ++j)
		{
			pass[j] = substr[i][j];
		}
		max = 1;
		max_index = 0;
		count = 1;
		qsort(substr, len+1, sizeof(substr[0]), sortf);
		for (i = 1; i <= len; ++i)
		{
			if ((len - i + count) < max)
				break;
			for (j = 0; j < size; ++j)
			{
				if (substr[i - 1][j] != substr[i][j])
				{
					break;
				}
			}
			if (j == size)
			{
				++count;
			}
			else
			{
				if (count > max)
				{
					max = count;
					max_index = i - 1;
				}
				count = 1;
			}
		}
		puts(substr[max_index]);
	}
}
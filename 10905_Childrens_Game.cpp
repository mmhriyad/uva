#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 51

#define MAXWORD 100

char numbers[MAXN][MAXWORD];
char out[1000];

int N;

int sortf2(const void *a, const void *b)
{
	char *num1 = (char *)a;
	char *num2 = (char *)b;
	char max1[MAXWORD * 2 + 1], max2[MAXWORD * 2 + 1];
	int i, j, i1, i2;
	i = 0;
	while (num1[i] && num2[i])
	{
		if (num1[i] != num2[i])
			return num2[i] - num1[i];
		max1[i] = num1[i];
		max2[i] = num2[i];
		++i;
	}
	j = i;
	if (num1[i])
	{
		while (num1[i])
		{
			max1[i] = num1[i];
			++i;
		}
	}
	i1 = i;
	i = j;
	if (num2[i])
	{
		while (num2[i])
		{
			max2[i] = num2[i];
			++i;
		}
	}
	i2 = i;
	j = 0;
	while (num2[j])
	{
		max1[i1] = num2[j];
		++i1;
		++j;
	}
	max1[i1] = '\0';
	j = 0;
	while (num1[j])
	{
		max2[i2] = num1[j];
		++i2;
		++j;
	}
	max2[i2] = '\0';

	i = 0;
	while (max1[i] == max2[i])
		++i;
	return max2[i] - max1[i];
	//return strcmp(max2, max1);
}

int sortf(const void *a, const void *b)
{
	char *num1 = (char *)a;
	char *num2 = (char *)b;

	int i, j;
	i=0;
	while (num1[i] && num2[i] && num1[i] == num2[i])
	{
		++i;
	}
	if (num1[i] && num2[i])
		return num2[i] - num1[i];
	else if (!num1[i] && !num2[i])
		return 0;
	else if (num1[i])
	{
		while (num1[i])
		{
			j = 0;
			while (num1[i] == num2[j] && num1[i] && num2[j])
			{
				++i;
				++j;
			}
			if (num2[j])
				break;
		}
		if (!num1[i])
			--i;
		if (num2[j])
			return num2[j] - num1[i];
		return num2[0] - num1[i]; //1
	}
	else
	{
		while (num2[i])
		{
			j = 0;
			while (num2[i] == num1[j] && num2[i] && num1[j])
			{
				++i;
				++j;
			}
			if (num1[j])
				break;
		}
		if (!num2[i])
			--i;
		if (num1[j])
			return num2[i] - num1[j]; //-1
		return num2[i] - num1[0]; //-1
	}
}

int main()
{
	/*freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int i, k, l;
	while (scanf("%d", &N) == 1 && N)
	{
		for (i = 0; i < N; ++i)
			scanf("%s", &numbers[i]);
		qsort(numbers, N, sizeof(numbers[0]), sortf);
		k = l = 0;
		for (i = 0; i < N; ++i)
		{
			k = 0;
			while (numbers[i][k])
			{
				out[l++] = numbers[i][k++];
			}
		}
		out[l] = 0x00;
		puts(out);
			//printf("%s", numbers[i]);
		//printf("\n");
	}
	return 0;
}
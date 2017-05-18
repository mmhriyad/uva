#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char arr[100];

int sortf(const void *a, const void *b)
{
	char *c1 = (char *)a;
	char *c2 = (char *)b;
	return *c1-*c2;
}

bool getnext()
{
	int len = strlen(arr);
	int i, j, mini;
	char min, tmp;
	for(i=len-1; i>0; i--)
	{
		if(arr[i]>arr[i-1])
			break;
	}
	if(i==0)
		return false;
	i--;
	min = 'z';
	for(j=i+1; j<len; j++)
	{
		if(arr[j] > arr[i] && arr[j] < min)
		{
			min = arr[j];
			mini = j;
		}
	}

	tmp = arr[i];
	arr[i] = arr[mini];
	arr[mini] = tmp;

	i++;
	qsort(arr+i, len-i, sizeof(char), sortf);

	return true;
}

int main()
{
	freopen("input.txt", "r", stdin);
	for(;;)
	{
		scanf("%s", arr);
		if(arr[0] == '#')
			break;
		if(getnext())
			printf("%s\n", arr);
		else
			printf("No Successor\n");
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <iostream>
using namespace std;

#define MAX 5843
#define MAXV 2000000000

int arr[MAX];
int mul[4] = {2,3,5,7};

set <int> s;

char *pos[] = {"th", "st", "nd", "rd", "th", "th", "th", "th", "th", "th", "th", "th", "th", "th", "th", "th"};

int sortf(const void *a, const void *b)
{
	int *i1 = (int *)a;
	int *i2 = (int *)b;
	return *i1 - *i2;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int i,j;
	long long int nextv;
	arr[0] = 0;
	arr[1] = 1;
	s.insert(0);
	s.insert(1);
	int count = 1, count_s = 1;
	for(i=1; i<MAX; i++)
	{
		for(j=0; j<4; j++)
		{
			nextv = (long long int)arr[i] * mul[j];

			if((nextv >1 && nextv <= MAXV) && s.find(nextv) == s.end())
			{
				arr[++count] = nextv;
				s.insert(nextv);
			}
			if(count == MAX)
				break;
		}
		if(count == MAX)
				break;
	}
	qsort(arr, MAX, sizeof(int), sortf);
	while(scanf("%d", &i) == 1 && i)
	{
		j = i%100;
		if(j == 11 || j == 12 || j == 13)
			j = j;
		else
			j = i%10;
		printf("The %d%s humble number is %d.\n", i, pos[j], arr[i]);
	}
}

#include "stdio.h"
#include "string.h"

char arr[21][21];
int count;

char* getsomething()
{
	char *tmp = "hello";
	return tmp;
}

int main()
{
	char* arr;
	unsigned char uarr[] = "01234234";
	int a;
	puts((char *)uarr);
	arr = (char *)uarr;
	puts(arr);
	printf("%d\n", strlen((char *)uarr));
	/*
	unsigned char j = 0xFF;
	printf("%x\n", j);
	if(j == 0xFF)
		printf("yes!!!\n");
		*/
	/*
	int M, N, i,j, x, y;
	
	while(scanf("%d %d", &M, &N) == 2)
	{
		count = 0;
		for(i=0; i<M; i++)
		{
			scanf("%s", &arr[0]);
			//gets(arr[0]);
			printf("you entered: %s\n", arr[0]);
		}
		scanf("%d %d", &x, &y);
	}
	*/
}
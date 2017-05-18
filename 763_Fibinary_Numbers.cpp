#include "stdio.h"
#include "string.h"
#include "math.h"
#include <stdlib.h> 
#include "conio.h"

long long int arrFib[101];

int FibinaryToNumber(char inp[], int len)
{
	int num=0, i, j;
	for(i=len-1,j=0; i>=0; i--,j++)
	{
		if(inp[i] == '1')
		{
			num += (int)(arrFib[j]);
		}
	}
	return num;
}

long long int NumberToFibinary(long long int num, int maxlen)
{
	int i=maxlen, orgnum=num, j=0;
	char arr[101];
	long long int sum=0;

	while(i>=0)
	{
		if(arrFib[i] <= num)
		{
			sum += (int)pow(10.0, i);
			num -= arrFib[i];
			arr[j++] = '1';
			printf("1");
		}
		else if(orgnum > num)
		{
			arr[j++] = '0';
			printf("0");
		}
		i--;
		//if(i<0) break;
	}
	printf("\n");
	arr[j]=0x00;
	sum = atoi(arr);
	return sum;
}

int main()
{
	int i, fibtonum, maxlen=0;
	long long int num1, num2, numtofib;
	char chrNum1[101], chrNum2[101];
	char ch='a';
	//int num1, num2;

	arrFib[0]=1;
	arrFib[1]=2;
	
	for(i=2; i<100; i++)
		arrFib[i] = arrFib[i-1] + arrFib[i-2];
	
	do
	{
	fgets (chrNum1, sizeof(chrNum1), stdin); chrNum1[strlen(chrNum1)-1]=0x00;
	fgets (chrNum2, sizeof(chrNum2), stdin); chrNum2[strlen(chrNum2)-1]=0x00;
	//scanf ("%[^\n]%*c", chrNum1);
	//gets(chrNum1);
	printf("\n");
	maxlen = strlen(chrNum1) > strlen(chrNum2) ? strlen(chrNum1) : strlen(chrNum2);

	num1 = FibinaryToNumber(chrNum1, strlen(chrNum1));
	num2 = FibinaryToNumber(chrNum2, strlen(chrNum2));
	numtofib = NumberToFibinary(num1+num2, maxlen*2);
	printf("%ld\n", numtofib);
	printf("\n");
	} while(chrNum1[0]);
/*
	i=0;
	while(ch != '\n')
	{
		ch = getchar();
		chrNum1[i++]=ch;
	}
	chrNum1[i-1]=0x00;

	printf("%s, %d", chrNum1, strlen(chrNum1));
*/
	//getch();
	return 0;
}
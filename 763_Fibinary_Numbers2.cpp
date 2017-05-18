#include "stdio.h"
#include "string.h"

#define MAXDIGIT 105

char inp1[MAXDIGIT], inp2[MAXDIGIT], extra[MAXDIGIT];
int len=0;

int exceed=0;
bool recurse=false;

void add1to(int pos)
{
	if(pos<0)
	{
		exceed=true;
		return;
	}
	if(inp1[pos] == '1')
	{
		inp1[pos] = '0';
		if(pos == len-1)
		{
			recurse=true;
			add1to(pos-1);
		}
		else if(pos == len-2)
		{
			recurse=true;
			add1to(pos+1);
			recurse=true;
			add1to(pos-1);
		}
		else if(pos <= len-3)
		{
			recurse=true;
			add1to(pos+2);
			recurse=true;
			add1to(pos-1);
		}
	}
	else if(inp1[pos] == '0')
	{
		inp1[pos] = '1';
		if( (pos > 0) && (inp1[pos-1] == '1'))
		{
			inp1[pos] = '0';
			inp1[pos-1] = '0';
			recurse=true;
			add1to(pos-2);
		}
		else if((pos < len) && (inp1[pos+1] == '1'))
		{
			inp1[pos] = '0';
			inp1[pos+1] = '0';
			recurse=true;
			add1to(pos-1);
		}
	}

	recurse=false;
}

int main()
{
	char tmp[MAXDIGIT];
	int t=0, n;
	int i=0,j=0;
	int len2;
	for(;;)
	{
		gets(inp1);
		if(0x00 == inp1[0]) return 0;
		gets(inp2);

	if(strlen(inp2) > strlen(inp1))
	{
		strcpy(tmp, inp2);
		strcpy(inp2, inp1);
		strcpy(inp1, tmp);
	}

	

	if(t++)
		printf("\n");
	len = strlen(inp1);
	len2 = strlen(inp2);
	
	for(i=len2-1,j=0; i>=0; i--,j++)
	{
		if(inp2[i]=='1')
			add1to(len - j - 1);
	}
	if(exceed)
	{
		printf("1");
		if(inp1[0]=='1')
		{
			inp1[0]='0';
			printf("0");
		}
	}
	exceed=false;
	printf("%s\n",inp1);

	gets(inp1);
	if(0x00 != inp1[0] || EOF == inp1[0]) return 0;
	}
	return 0;
}
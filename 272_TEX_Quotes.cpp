#include <stdio.h>

#define FIND '"'

int main()
{
	//freopen("input.txt", "r", stdin);
	bool start = false;
	char ch;
	for(;;)
	{
		ch = getchar();
		if(ch == EOF)
			return 0;
		if(ch == FIND)
		{
			if(start)
			{
				printf("''");
				start = false;
			}
			else
			{
				printf("``");
				start = true;
			}
		}
		else
			putchar(ch);
	}
}
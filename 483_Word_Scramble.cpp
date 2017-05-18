#include <stdio.h>

char arr[500], ch;

int main()
{
	//freopen("input.txt", "r", stdin);
	int i, count = 0;
	for(;;)
	{
		ch = getchar();
		if(ch == EOF)
		{
			for(i=count-1; i>=0; i--)
				putchar(arr[i]);
			return 0;
		}
		if(ch == ' ' || ch == '\n')
		{
			for(i=count-1; i>=0; i--)
				putchar(arr[i]);
			putchar(ch);
			count = 0;
		}
		else
			arr[count++] = ch;
	}
}
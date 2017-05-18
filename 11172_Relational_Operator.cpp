#include "stdio.h"

int main()
{
	int T, i;
	long long int a, b;
	char ch;
	scanf("%d", &T);
	for(i=0; i<T; i++)
	{
		scanf("%lld %lld", &a, &b);
		ch = '=';
		if(a>b)
			ch = '>';
		else if(a<b)
			ch = '<';
		printf("%c\n", ch);
	}
	return 0;
}
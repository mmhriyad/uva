#include <stdio.h>

int main()
{
	int n, s, count;
	while(scanf("%d %d", &n, &s) == 2)
	{
		count = n;
		while(n>=s)
		{
			count += n/s;
			n = n/s + n%s;
		}
		printf("%d\n", count);
	}
}
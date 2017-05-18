#include <stdio.h>

int main()
{
	int n, s, d, i;
	//freopen("input.txt", "r", stdin);;
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d %d", &s, &d);
		
		if(((s > d) && ((s+d)%2 == 0) && ((s-d)%2 == 0)) || (s == 0 && d == 0))
			printf("%d %d\n", (s+d)/2, (s-d)/2);
		else
			printf("impossible\n");
			
	}
}

/*
input:
13
15 10
88 9
155 22
20 10
40 12
75 25
13 7
888 222
9999 1111
12365 123
99 11
13 19
0 0

output:
impossible
impossible
impossible
15 5
26 14
50 25
10 3
555 333
5555 4444
6244 6121
55 44
impossible
0 0
*/
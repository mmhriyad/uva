#include <stdio.h>
#include <math.h>

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int a, b, min, max, i, count;

	while (scanf("%d %d", &a, &b) == 2)
	{
		if (a == 0 && b == 0)
			return 0;
		
		min = (int)ceil(sqrt((double)a));
		max = (int)(sqrt((double)b));
		printf("%d\n", max - min + 1);
	}
}
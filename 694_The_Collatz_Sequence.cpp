#include <stdio.h>

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int A, limit, count, cn;
	long long int n;
	cn = 0;
	while (scanf("%d %d", &A, &limit) == 2)
	{
		if (A < 0 && limit < 0)
			break;
		count = 1;
		n = A;
		while (n > 1 && n <= limit)
		{
			if (n & 1)
				n = n * 3 + 1;
			else
				n = n >> 1;
			if (n > limit)
				break;
			++count;
		}
		printf("Case %d: A = %d, limit = %d, number of terms = %d\n", ++cn, A, limit, count);
	}
	return 0;
}
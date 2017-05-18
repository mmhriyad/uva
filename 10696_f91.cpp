#include <stdio.h>

int main()
{
	int N;
	while (scanf("%d", &N) == 1 && N)
	{
		if (N > 100)
			printf("f91(%d) = %d\n", N, N - 10);
		else
			printf("f91(%d) = 91\n", N);
	}
	return 0;
}
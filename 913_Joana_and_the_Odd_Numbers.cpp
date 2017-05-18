#include <stdio.h>

int main()
{
	long long int a, n, d, an, last_num, sum;
	while (scanf("%lld", &an) == 1)
	{
		n = (an - 1) / 2 + 1;
		sum = (n * (1 + an))/2;
		last_num = sum * 2 - 1;
		last_num = last_num * 3 - 6;
		printf("%lld\n", last_num);
	}
	return 0;
}
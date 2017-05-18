#include <stdio.h>

int get_degree(int n, int count)
{
	int sum = 0;
	if (n == 9)
		return count;
	while (n)
	{
		sum += n % 10;
		n /= 10;
	}
	get_degree(sum, count + 1);
}

int main()
{
	int i, sum, deg;
	char inp[1005];
	while (gets(inp))
	{
		if (inp[0] == '0')
			break;
		sum = 0;
		i = 0;
		while (inp[i])
		{
			sum += (inp[i] - '0');
			i++;
		}
		if (sum % 9 == 0)
		{
			deg = get_degree(sum, 1);
			printf("%s is a multiple of 9 and has 9-degree %d.\n", inp, deg);
		}
		else
			printf("%s is not a multiple of 9.\n", inp, deg);
	}
}
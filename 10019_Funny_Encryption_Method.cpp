#include <stdio.h>

int nbin[10000];

void calculate(int num)
{
	int n, count;
	n = num;
	count = 0;
	while (n)
	{
		if (n & 1)
			++count;
		n = n >> 1;
	}
	nbin[num] = count;
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int n, T, i, b1, b2, num;
	nbin[0] = 0;
	for (i = 1; i < 10; ++i)
	{
		calculate(i);
	}
	for (i = 10; i < 10000; ++i)
		nbin[i] = 0;

	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		if (!nbin[n])
			calculate(n);
		b1 = nbin[n];
		b2 = 0;
		num = n;
		while (num)
		{
			b2 += nbin[num % 10];
			num /= 10;
		}
		printf("%d %d\n", b1, b2);
	}

	return 0;
}
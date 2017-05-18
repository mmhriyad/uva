#include <stdio.h>

char bin[33], rev_bin[33];
int res;

void tobin(int n)
{
	int i, a, k;
	for (i = 0; i < 32; ++i)
	{
		a = (1 << (31 - i));
		if (n&a)
			bin[i] = '1';
		else
			bin[i] = '0';
	}
	bin[32] = 0x00;

	for (i = 0; i < 4; ++i)
	{
		for (k = 0; k < 8; ++k)
		{
			rev_bin[((3 - i) << 3) + k] = bin[(i << 3) + k];
		}
	}
	rev_bin[32] = 0x00;
	res = 0;
	if (rev_bin[0] == '1')
	{
		for (i = 1; i < 32; ++i)
		{
			if (rev_bin[i] == '0')
				res = res + (1 << (31 - i));
		}
		res = -res - 1;
	}
	else
	{
		for (i = 1; i < 32; ++i)
		{
			if (rev_bin[i] == '1')
				res = res + (1 << (31-i));
		}
	}
}

int main()
{
	/*freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int n;
	while (scanf("%d", &n) == 1)
	{
		tobin(n);
		//puts(bin);
		//puts(rev_bin);
		printf("%d converts to %d\n", n, res);
	}
	return 0;
}
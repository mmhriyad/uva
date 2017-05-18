//623 - 500!
#include <stdio.h>

#define MAXN 1001
#define MAXL 3000

char out[MAXN][MAXL];
int n, N;

int facto(int a, int len)
{
	int i, k, prev, num, carry, rem, j;
	char tmp[MAXL];
	k = MAXL - 1;
	i = len - 1;
	prev = a - 1;
	carry = 0;
	while (i >= 0)
	{
		num = (out[prev][i] - '0') * a + carry;
		carry = num / 10;
		rem = num % 10;
		tmp[k--] = (rem + '0');
		--i;
	}
	while (carry)
	{
		num = carry;
		carry = num % 10;
		tmp[k--] = (carry + '0');
		carry = num / 10;
	}
	
	++k;

	for (i = k, j = 0; i < MAXL; ++i, ++j)
	{
		out[a][j] = tmp[i];
	}

	out[a][j] = 0x00;
	
	return j;
}

void init()
{
	int i, len;
	sprintf(out[0], "1");
	sprintf(out[1], "1");
	sprintf(out[2], "2");
	sprintf(out[3], "6");
	len = 1;
	for (i = 4; i < MAXN; ++i)
	{
		len = facto(i, len);
	}
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	init();
	while (scanf("%d", &N) == 1)
	{
		printf("%d!\n", N);
		puts(out[N]);
	}

	return 0;
}
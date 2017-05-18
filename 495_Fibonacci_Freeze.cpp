#include <stdio.h>
#include <string.h>

#define MAXN 5001
#define MAXL 10000

char fibnumbers[MAXN][MAXL];

void calculate(int a)
{
	int b, c, i1, carry, sum, i2, k;
	char tmp[MAXL];
	b = a - 1;
	c = a - 2;
	i1 = strlen(fibnumbers[b]) - 1;
	i2 = strlen(fibnumbers[c]) - 1;

	k = i1;

	tmp[k + 1] = 0x00;
	carry = 0;
	while (i1 >= 0 && i2 >= 0)
	{
		sum = fibnumbers[b][i1] - '0' + fibnumbers[c][i2] - '0' + carry;
		carry = sum / 10;
		sum = sum % 10;
		tmp[k] = sum + '0';
		--k;
		--i1;
		--i2;
	}

	while (i1 >= 0)
	{
		sum = fibnumbers[b][i1] - '0' + carry;
		carry = sum / 10;
		sum = sum % 10;
		tmp[k] = sum + '0';
		--k;
		--i1;
	}

	while (i2 >= 0)
	{
		sum = fibnumbers[c][i2] - '0' + carry;
		carry = sum / 10;
		sum = sum % 10;
		tmp[k] = sum + '0';
		--k;
		--i2;
	}
	if (carry)
		sprintf(fibnumbers[a], "%d%s", carry, tmp);
	else
		sprintf(fibnumbers[a], "%s", tmp);
}

void init()
{
	int i;
	sprintf(fibnumbers[0], "%s", "0");
	sprintf(fibnumbers[1], "%s", "1");
	sprintf(fibnumbers[2], "%s", "1");
	sprintf(fibnumbers[3], "%s", "2");
	for (i = 4; i < MAXN; ++i)
		calculate(i);
}

int main()
{
	/*freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int a;
	init();
	while (scanf("%d", &a) == 1)
	{
		printf("The Fibonacci number for %d is %s\n", a, fibnumbers[a]);
	}
	return 0;
}
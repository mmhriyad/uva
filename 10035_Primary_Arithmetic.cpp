#include <stdio.h>

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	char num1[15], num2[15];
	int i, j, carry, nc;
	while (scanf("%s %s", num1, num2) == 2)
	{
		if (num1[0] == '0' && num2[0] == '0')
			break;
		i = j = 0;
		nc = 0;
		carry = 0;
		while (num1[++i]);
		--i;
		while (num2[++j]);
		--j;
		carry = 0;
		while (i >= 0 && j >= 0)
		{
			carry = ((num1[i] - '0') + (num2[j] - '0')) + carry;
			carry /= 10;
			if (carry)
				++nc;
			--i;
			--j;
		}
		while (carry && i >= 0)
		{
			carry = (num1[i] - '0') + carry;
			carry /= 10;
			if (carry)
				++nc;
			--i;
		}
		while (carry && j >= 0)
		{
			carry = (num2[j] - '0') + carry;
			carry /= 10;
			if (carry)
				++nc;
			--j;
		}
		if (nc == 0)
			printf("No carry operation.\n");
		else if (nc == 1)
			printf("1 carry operation.\n");
		else if (nc > 1)
			printf("%d carry operations.\n", nc);
	}
}
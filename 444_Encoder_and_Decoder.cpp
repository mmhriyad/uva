#include <stdio.h>

char inp[300], out[300];

int n;

void add_num(int num)
{
	int a, b;
	a = num;
	while (a)
	{
		b = a % 10;
		out[n++] = b + '0';
		a = a / 10;
	}
}

void add_char(char c)
{
	out[n++] = c;
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	char ch;
	int i;
	while (gets(inp))
	{
		i = 0;
		n = 0;
		while (inp[i++]);
		i -= 2;
		if (inp[0] >= '0' && inp[0] <= '9') //decode
		{
			while (i >= 0)
			{
				ch = (inp[i] - '0') * 10 + (inp[i - 1] - '0');
				if (ch < 32)
				{
					ch = (inp[i] - '0') * 100 + (inp[i - 1] - '0') * 10 + (inp[i - 2] - '0');
					--i;
				}
				add_char(ch);
				i -= 2;
			}
		}
		else //endcode
		{
			while (i >= 0)
			{
				add_num(int(inp[i]));
				--i;
			}
		}
		out[n] = 0x00;
		puts(out);
	}

	return 0;
}
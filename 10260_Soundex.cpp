#include <stdio.h>

int main()
{
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int value[26] = { 0, 1, 2, 3, 0, 1, 2, 0, 0, 2, 2, 4, 5, 5, 0, 1, 2, 6, 2, 3, 0, 1, 0, 2, 0, 2 };
	char inp[30], out[30];
	int i, n, cval, pval, result;
	while (gets(inp))
	{
		cval = pval = 0;
		i = 0;
		n = 0;
		result = 0;
		while (inp[i])
		{
			cval = value[inp[i] - 'A'];
			if (pval != cval)
			{
				pval = cval;
				if (pval)
					out[n++] = pval + '0';
			}
			++i;
		}
		out[n] = 0x00;
		puts(out);
	}
}
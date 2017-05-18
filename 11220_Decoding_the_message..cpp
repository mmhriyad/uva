//11220 - Decoding the message.
#include <stdio.h>

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int T, cn, i, k, pos;
	char inp[1000], wrd[50];
	scanf("%d", &T);
	gets(inp);
	gets(inp);
	for (cn = 1; cn <= T; ++cn)
	{
		if (cn > 1)
			printf("\n");
		printf("Case #%d:\n", cn);
		while (gets(inp))
		{
			if (!inp[0])
				break;
			i = 0;
			k = 0;
			while (inp[i])
			{
				pos = 0;
				
				while (inp[i] && inp[i] != ' ')
				{
					if (pos == k)
						break;
					++i;
					++pos;
				}
				if (pos == k && inp[i] != ' ')
					wrd[k++] = inp[i++];

				while (inp[i] && inp[i] != ' ')
					++i;
				if (inp[i])
					++i;
			}
			wrd[k] = 0x00;
			puts(wrd);
		}
	}

	return 0;
}
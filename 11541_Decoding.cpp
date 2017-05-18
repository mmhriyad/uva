//11541 - Decoding
#include <stdio.h>

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	char inp[1000], out[5000], ch;
	int T, i, num, k, cn, l;
	scanf("%d", &T);
	gets(inp);
	for (cn = 1; cn <= T; ++cn)
	{
		gets(inp);
		i = 0;
		l = 0;
		while (inp[i])
		{
			while (inp[i] && inp[i] >= 'A' && inp[i] <= 'Z')
			{
				ch = inp[i];
				out[l++] = inp[i++];
			}
			num = 0;
			while (inp[i] && inp[i] >= '0' && inp[i] <= '9')
			{
				num = num * 10 + (inp[i] - '0');
				++i;
			}
			for (k = 1; k < num; ++k)
			{
				out[l++] = ch;
			}
		}
		out[l] = 0x00;
		printf("Case %d: %s\n", cn, out);
	}

	return 0;
}

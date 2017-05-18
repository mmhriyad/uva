//492 - Pig-Latin
#include <stdio.h>

#define MAXL 1000000
#define IS_VOWEL(a) (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U')
#define IS_WORD(a) ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))

char inp[MAXL], out[MAXL];

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int i, n, count;
	char ch;
	while (gets(inp))
	{
		n = 0;
		i = 0;
		while (inp[i])
		{
			count = 0;
			if (IS_VOWEL(inp[i]))
			{
				while (inp[i] && IS_WORD(inp[i]))
				{
					out[n++] = inp[i++];
					++count;
				}
			}
			else
			{
				if (IS_WORD(inp[i]))
				{
					ch = inp[i++];
					++count;
				}
				while (inp[i] && IS_WORD(inp[i]))
				{
					out[n++] = inp[i++];
					++count;
				}
				if (count)
					out[n++] = ch;
			}

			if (count)
			{
				out[n++] = 'a';
				out[n++] = 'y';
			}

			if (inp[i])
				out[n++] = inp[i++];
		}
		out[n] = 0x00;
		puts(out);
	}

	return 0;
}

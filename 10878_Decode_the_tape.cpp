#include <stdio.h>

int main()
{
	/*freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	char res, inp[100], val, ch;
	int i;
	while (gets(inp))
	{
		i = 0;
		res = 0;
		if (inp[i] == '_')
			continue;
		while (inp[i])
		{
			ch = inp[i];
			if (ch == ' ' || ch == 'o')
			{
				if (inp[i] == ' ')
					val = 0;
				else val = 1;
				res = res * 2 + val;
			}
			++i;
		}

		printf("%c", res);
	}
}
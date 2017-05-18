#include <stdio.h>

char outarr[200][50];

int main()
{
	/*freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int N, count;
	while (scanf("%d", &N) == 1)
	{
		int i, N2, a, b , an, amn;
		N2 = N << 1;
		count = 0;
		
		for (i = N + 1; i <= N2; ++i)
		{
			a = i;
			
			amn = a - N;
			an = a * N;

			if (an % amn == 0)
			{
				b = an / amn;
				sprintf(outarr[count++], "1/%d = 1/%d + 1/%d", N, b, a);
			}
		}

		printf("%d\n", count);
		for (i = 0; i < count; ++i)
			puts(outarr[i]);
	}
	return 0;
}
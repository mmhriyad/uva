#include <stdio.h>
#include <math.h>

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int Vt, Vo;

	while (scanf("%d %d", &Vt, &Vo) == 2)
	{
		if (Vt == 0 && Vo == 0)
			break;

		int len, len_max, i, imax, count;
		double D, V;
		bool is_unique = true;
		imax = Vt / Vo;
		len_max = 0;
		count = 0;

		for (i = 1; i < imax; ++i)
		{
			V = (double)Vt / i;
			if (V <= Vo)
				break;
			D = (sqrt((V - Vo)) * 3);
			len = (int)((D * i) * 1000);
			if (len > len_max)
			{
				len_max = len;
				count = i;
				is_unique = true;
			}
			else if (len == len_max)
			{
				is_unique = false;
				count = 0;
			}
		}

		printf("%d\n", count);
	}

	return 0;
}
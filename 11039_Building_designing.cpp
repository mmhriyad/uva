#include <stdio.h>
#include <stdlib.h>

#define MAXN 500001

int red[MAXN], blue[MAXN];

int sortf(const void *a, const void *b)
{
	int *num1 = (int *)a;
	int *num2 = (int *)b;

	return *num2 - *num1;
}

int main()
{
	/*freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int T, N, num, b, r, i, k, count, current;
	bool clr_blue;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		b = r = 0;
		while (N--)
		{
			scanf("%d", &num);
			if (num > 0)
				blue[b++] = num;
			else
				red[r++] = -num;
		}
		qsort(red, r, sizeof(int), sortf);
		qsort(blue, b, sizeof(int), sortf);

		i = k = 0;
		count = 0;
		
		if (!b && !r)
			count = 0;
		else if (!b)
		{
			clr_blue = false;
			count = 1;
		}
		else if (!r)
		{
			clr_blue = true;
			count = 1;
		}
		else if (red[0] > blue[0])
		{
			clr_blue = false;
			current = red[0] + 1;
		}
		else
		{
			clr_blue = true;
			current = blue[0] + 1;
		}
		
		while (i < b && k < r)
		{
			if (!clr_blue)
			{
				while (k < r && current <= red[k])
				{
					++k;
				}
				if (k < r)
				{
					current = red[k];
					++count;
					clr_blue = true;
				}
			}
			else
			{
				while (i < b && current <= blue[i])
				{
					++i;
				}
				if (i < b)
				{
					current = blue[i];
					++count;
					clr_blue = false;
				}
			}
		}// while


		printf("%d\n", count);
	}
}
#include <stdio.h>

#define MAXN 1000001

typedef unsigned int lli;

lli arr[MAXN];


void init()
{
	lli i, num, count;
	arr[0] = 0;
	for (i = 1; i < MAXN; ++i)
	{
		num = i;
		count = 1;
		while (num != 1)
		{
			if (num % 2 == 1)
				num = 3 * num + 1;
			else
				num = num >> 1;
			++count;
		}
		arr[i] = count;
	}
}

int main()
{
	/*freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/

	lli L, U, max, last, tmp, i, num, count, max_num, l, u;
	last = 1;
	init();
	while (scanf("%u %u", &L, &U) == 2)
	{
		if (L == 0 && U == 0)
			break;
		l = L;
		u = U;
		if (L > U)
		{
			tmp = L;
			L = U;
			U = tmp;
		}
		//max = 0;
		//max_num = 0;
		//if (last <= U)
		//{
		//	for (i = last; i <= U; ++i)
		//	{
		//		num = i;
		//		count = 1;
		//		while (num != 1)
		//		{
		//			if (num % 2 == 1)
		//				num = 3 * num + 1;
		//			else
		//				num = num >> 1;
		//			++count;
		//		}
		//		arr[i] = count;
		//		if (max < count)
		//		{
		//			max = count;
		//			max_num = i;
		//		}
		//	} // end for
		//	last = U;
		//} // end if
		//if (max_num == 0)
		{
			max = 0;
			max_num = 0;
			for (i = L; i <= U; ++i)
			{
				if (arr[i] > max)
				{
					max = arr[i];
					max_num = i;
				}
			}
		}
		printf("%u %u %u\n", l, u, max);
	}

	return 0;
}
#include <stdio.h>

typedef long long int lli;

//lli arr[100000001];

int main()
{
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	lli L, U, max, last, tmp, i, num, count, max_num, l, u;
	last = 1;
	while (scanf("%lld %lld", &L, &U) == 2)
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
		max = 0;
		max_num = 0;
		last = L;
		//if (last <= U)
		{
			for (i = last; i <= U; ++i)
			{
				num = i;
				count = 0;
				do
				{
					if (num % 2 == 1)
						num = 3 * num + 1;
					else
						num = num / 2;
					++count;
				} while (num != 1);
				//arr[i] = count;
				if (max < count)
				{
					max = count;
					max_num = i;
				}
			} // end for
			last = U;
		} // end if
		//if (max_num == 0)
		/*{
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
		}*/
		printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n", L, U, max_num, max);
		
	}

	return 0;
}
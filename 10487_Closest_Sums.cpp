#include <stdio.h>

int main()
{
	/*freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/

	int min, max, res, n, m, i, q, k, sum, diff, pdiff;
	int case_no = 0;
	bool calculatedmin;
	int arr[1000];
	while (scanf("%d", &n) == 1 && n)
	{
		min = 1 << 30;
		max = 0;
		for (i = 0; i < n; ++i)
		{
			scanf("%d", &arr[i]);
		}
		min = max = -1;
		calculatedmin = false;
		printf("Case %d:\n", ++case_no);
		scanf("%d", &m);
		while (m--)
		{
			scanf("%d", &q);
			printf("Closest sum to %d is ", q);

			if (calculatedmin && (q <= min || q >= max))
			{
				if (q <= min)
					printf("%d", min);
				else if (q >= max)
					printf("%d", max);
			}
			else
			{
				res = 1 << 30;
				if (min < 0)
				{
					min = 1 << 30;
					max = 0;
				}
				diff = res;
				pdiff = diff;
				for (i = 0; i < (n - 1); ++i)
				{
					for (k = i + 1; k < n; ++k)
					{
						sum = arr[i] + arr[k];
						if (sum > q)
							diff = sum - q;
						else
							diff = q - sum;

						if (diff < pdiff)
						{
							res = sum;
							pdiff = diff;
						}
						if (!calculatedmin)
						{
							if (sum > max)
								max = sum;
							if (sum < min)
								min = sum;
						}
						if (calculatedmin && diff == 0)
							break;
					} // for k
					if (calculatedmin && diff == 0)
						break;
				} // for i
				printf("%d", res);
				calculatedmin = true;
			}
			printf(".\n");
		} // while m
		
	}

	return 0;
}
#include <stdio.h>

#define MAXN (500 * 30000)

#define GET_MAX(x, y) (x > y ? x : y)
#define GET_MIN(x, y) (x < y ? x : y)
#define GET_DIFF(x, y) (x > y ? (x - y) : (y - x))

int main()
{
	//freopen("inp.txt", "r", stdin);
	int i, j, T, r, a;
	long long int min, sum;
	int arr[500];

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &r);
		min = MAXN;
		
		for (i = 0; i < r; i++)
		{
			scanf("%d", &arr[i]);
		}

		for (i = 0; i < r; i++)
		{
			sum = 0;
			for (j = 0; j < r; j++)
			{
				sum += GET_DIFF(arr[i], arr[j]);
			}
			min = GET_MIN(sum, min);
		}
		printf("%lld\n", min);
	}

	return 0;
}

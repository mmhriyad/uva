#include <stdio.h>

#define INF (1 << 30)

int numbers[100000];


int main()
{
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T, N, i, j, max, diff;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &N);
		max = -INF;
		for (i = 0; i < N; ++i)
		{
			scanf("%d", &numbers[i]);
			for (j = i - 1; j >= 0; --j)
			{
				diff = numbers[j] - numbers[i];
				if (diff > max)
					max = diff;
			}
		}

		printf("%d\n", max);
	}

	return 0;
}
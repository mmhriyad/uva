#include <stdio.h>

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int arr[1001], N, T, i;
	double avg, percnt, sum, below_avg;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		sum = 0;
		for (i = 0; i < N; i++)
		{
			scanf("%d", &arr[i]);
			sum += arr[i];
		}

		avg = sum / N;

		below_avg = 0;
		for (i = 0; i < N; i++)
		{
			if (arr[i] > avg)
				++below_avg;
		}

		percnt = (((double)below_avg) / N) * 100.0;

		printf("%.3lf%%\n", percnt);
		
	}
}
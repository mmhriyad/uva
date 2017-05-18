#include <stdio.h>

#define MAXN 3651
#define MAXP 101

int N, P, parties[MAXP], count;
bool isHartal[MAXN];

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T, i, h, j, holidays;
	scanf("%d", &T);
	while (T--)
	{
		count = 0;
		scanf("%d", &N);
		for (i = 0; i <= N; ++i)
		{
			isHartal[i] = false;
		}
		scanf("%d", &P);
		for (i = 0; i < P; ++i)
		{
			scanf("%d", &h);
			for (j = h; j <= N; j += h)
			{
				holidays = j % 7;
				if (holidays != 0 && holidays != 6 && !isHartal[j])
				{
					isHartal[j] = true;
					++count;
				}
			}
		}

		printf("%d\n", count);
	}
}
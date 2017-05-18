//1482 - Playing With Stones : not completed, not submitted
#include <stdio.h>

bool is_pos(long long int a)
{
	int count;
	long long int n;
	count = 0;
	n = a;
	while (n)
	{
		if ((n & 1) == 0)
			return true;
		n = n >> 1;
	}
	return false;
}

int main()
{
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	long long int a;
	int count[101], sum;

	int i, N, T;
	bool can_win;
	int win_count;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		can_win = true;
		win_count = 0;
		for (i = 0; i < N; ++i)
		{
			scanf("%lld", &a);
			can_win = is_pos(a);
			if (can_win)
				++win_count;
		}
		if (win_count & 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
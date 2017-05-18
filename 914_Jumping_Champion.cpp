#include <stdio.h>
#include <math.h>

#define MAXN 1000005
#define MAXD 200

bool isPrime[MAXN];

int primelist[MAXN], np;
int difflist[MAXN], nd;

void sieve_of_Eratosthenes()
{
	int i, j, limit;
	np = nd = 0;
	limit = int(sqrt(double(MAXN)));
	for (i = 0; i < MAXN; i++)
		isPrime[i] = true;
	isPrime[0] = isPrime[1] = false;

	for (i = 2; i <= limit; ++i)
	{
		if (isPrime[i])
		{
			for (j = i + i; j < MAXN; j += i)
			{
				isPrime[j] = false;
			}
		}
	}

	for (i = 0; i < MAXN; i++)
	{
		if (isPrime[i])
			primelist[np++] = i;
	}
}

void generate_prime()
{
	sieve_of_Eratosthenes();
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	generate_prime();
	int i, j;
	int a, b, T, diff, cnt;
	int count[MAXD], max_count, max_num;
	bool multi;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &a, &b);
		max_count = 0;
		cnt = 0;
		for (i = 0; i < MAXD; ++i)
			count[i] = 0;
		for (i = 0; i < np && primelist[i] <= b; ++i)
		{
			if (primelist[i] >= a)
				++cnt;
			if (cnt > 1)
			{
				diff = primelist[i] - primelist[i - 1];
				++count[diff];
				if (count[diff] > max_count)
				{
					max_count = count[diff];
					max_num = diff;
				}
			}
		}

		if (max_count > 0)
		{
			multi = false;
			for (i = 0; i < MAXD; ++i)
			{
				if (i != max_num && count[i] == max_count)
				{
					multi = true;
					break;
				}
			}
			if (!multi)
				printf("The jumping champion is %d\n", max_num);
			else
				printf("No jumping champion\n");
		}
		else
			printf("No jumping champion\n");
	}
	return 0;

}
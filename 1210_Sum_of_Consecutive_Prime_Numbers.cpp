#include <stdio.h>
#include <math.h>

#define MAXN 10000

bool isPrime[MAXN + 1];

int prime_list[MAXN + 1], total_prime, count[MAXN + 1];

void sieve_of_Eratosthenes()
{
	int i, j, k, limit, sum;
	total_prime = 0;
	limit = int(sqrt(double(MAXN)));
	
	for (i = 0; i <= MAXN; i++)
	{
		isPrime[i] = true;
		count[i] = 0;
	}
	isPrime[0] = isPrime[1] = false;

	for (i = 2; i <= limit; ++i)
	{
		if (isPrime[i])
		{
			for (j = i + i; j <= MAXN; j += i)
			{
				isPrime[j] = false;
			}
		}
	}

	for (i = 0; i <= MAXN; i++)
	{
		if (isPrime[i])
			prime_list[total_prime++] = i;
		count[i] = 0;
	}

	for (i = 0; i < total_prime; ++i)
	{
		sum = 0;
		for (j = i; j < total_prime; ++j)
		{
			sum += prime_list[j];
			if (sum > MAXN)
				break;
			++count[sum];
				
		}
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
	int n;
	generate_prime();
	while (scanf("%d", &n) == 1 && n)
	{
		printf("%d\n", count[n]);
	}
	return 0;
}
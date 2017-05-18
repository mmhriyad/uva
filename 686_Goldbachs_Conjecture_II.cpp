#include <stdio.h>
#include <math.h>

#define MAXN 32768

bool isPrime[MAXN + 1];

void sieve_of_Eratosthenes()
{
	int i, j, limit;
	limit = int(sqrt(double(MAXN)));
	for (i = 0; i < MAXN; i++)
		isPrime[i] = true;
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
}

void generate_prime()
{
	sieve_of_Eratosthenes();
}

int get_pair_count(int n)
{
	int pair_count = 0;
	/*if (n % 2)
	{
	first_prime = 2;
	return isPrime[n - first_prime];
	}
	else*/
	{
		int i, limit = n / 2;
		for (i = 2; i <= limit; ++i)
		{
			if (isPrime[i] && isPrime[n - i])// && (i != n - i))
			{
				++pair_count;
			}
		}
		return pair_count;
	}
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n;
	generate_prime();
	while (scanf("%d", &n) == 1 && n)
	{
		printf("%d\n", get_pair_count(n));
	}
	return 0;
}
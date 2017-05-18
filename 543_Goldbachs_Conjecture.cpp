#include <stdio.h>
#include <math.h>

#define MAXN 1000000

bool isPrime[MAXN + 1];

int first_prime;

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

bool isPossible(int n)
{
	/*if (n % 2)
	{
		first_prime = 2;
		return isPrime[n - first_prime];
	}
	else*/
	{
		int i, limit = n / 2;
		for (i = 3; i <= limit; ++i)
		{
			if (isPrime[i] && isPrime[n - i])// && (i != n - i))
			{
				first_prime = i;
				return true;
			}
		}
		return false;
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
		if (isPossible(n))
			printf("%d = %d + %d\n", n, first_prime, n - first_prime);
		else
			printf("Goldbach's conjecture is wrong.\n");
	}
	return 0;
}
#include <stdio.h>
#include <math.h>

#define MAXN 20000000
#define MAXTP 100001

bool isPrime[MAXN + 1];

typedef struct
{
	int pnum1, pnum2;
}t_twin_prime;

t_twin_prime twin_primes[MAXTP + 1];
int NTP, NP, prime_list[MAXN];


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

	NTP = NP = 0;
	for (i = 0; i <= MAXN && NTP < MAXTP; ++i)
	{
		if (isPrime[i])
		{
			prime_list[NP] = i;
			if (NP > 0 && ((prime_list[NP] - prime_list[NP - 1]) == 2))
			{
				++NTP;
				twin_primes[NTP].pnum1 = prime_list[NP - 1];
				twin_primes[NTP].pnum2 = prime_list[NP];
			}
			++NP;
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
	int n = MAXN;
	generate_prime();
	while (scanf("%d", &n) == 1 && n)
	{
		printf("(%d, %d)\n", twin_primes[n].pnum1, twin_primes[n].pnum2);
	}
	return 0;
}
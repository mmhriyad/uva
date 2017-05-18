#include <stdio.h>
#include <math.h>

#define MAXN 1000000

bool isPrime[MAXN + 1];
int digit_prime[MAXN + 1];

bool is_digit_prime(int n)
{
	int sum = 0;
	sum = 0;
	while (n)
	{
		sum += n % 10;
		n /= 10;
	}
	n = sum;
	return isPrime[n];
}

void sieve_of_Eratosthenes()
{
	int i, j, limit;
	limit = int(sqrt(double(MAXN)));
	for (i = 0; i < MAXN; i++)
		isPrime[i] = true;
	isPrime[0] = isPrime[1] = false;
	digit_prime[0] = digit_prime[1] = 0;
	for (i = 2; i <= limit; ++i)
	{
		if (isPrime[i])
		{
			digit_prime[i] = digit_prime[i - 1] + is_digit_prime(i);
			for (j = i + i; j <= MAXN; j += i)
			{
				isPrime[j] = false;
			}
		}
		else
			digit_prime[i] = digit_prime[i - 1];
	}
	for (; i <= MAXN; ++i)
	{
		if (isPrime[i])
		{
			digit_prime[i] = digit_prime[i - 1] + is_digit_prime(i);
		}
		else
			digit_prime[i] = digit_prime[i - 1];
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
	int T, a, b;
	generate_prime();
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", digit_prime[b] - digit_prime[a - 1]);
	}
	return 0;
}
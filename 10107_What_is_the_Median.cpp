#include <stdio.h>

#define MAXN 10000

long long int arr[MAXN], N;

void insert(int number)
{
	int i, pos;
	for (i = 0; i < N; ++i)
	{
		if (arr[i] > number)
		{
			break;
		}
	}
	pos = i;
	for (i = N - 1; i >= pos; --i)
	{
		arr[i + 1] = arr[i];
	}
	arr[pos] = number;
	++N;
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int a, index;
	N = 0;
	while (scanf("%d", &a) == 1)
	{
		insert(a);
		index = N / 2;
		if (N % 2)
		{
			printf("%lld\n", arr[index]);
		}
		else
			printf("%lld\n", (arr[index] + arr[index - 1]) / 2);
	}
}
#include <stdio.h>

#define MAXN ((1<<30) - 1)
#define MAXF 45
#define MAXC 105

int arr_fib[MAXF];

int get_index(int n)
{
	int i;
	for (i = 0; i < MAXF; ++i)
		if (arr_fib[i] == n)
			return i;
	return 0;
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int i;
	
	arr_fib[0] = 1;
	arr_fib[1] = 2;

	for (i = 2; i < MAXF; ++i)
	{
		arr_fib[i] = arr_fib[i - 1] + arr_fib[i - 2];
	}

	int T, N, max_len, a, index, pos;
	int arr[MAXC];
	char cipher[MAXC], ch;
	char decipher[MAXC];
	
	scanf("%d", &T);
	while (T--)
	{
		for (i = 0; i < MAXC; ++i)
			decipher[i] = ' ';
		max_len = 0;
		scanf("%d", &N);
		for (i = 0; i < N; ++i)
		{
			scanf("%d", &arr[i]);
		}
		gets(cipher);
		gets(cipher);
		i = 0;
		ch = cipher[i];
		pos = 0;
		while (ch)
		{
			if (ch >= 'A' && ch <= 'Z')
			{
				index = get_index(arr[pos]);
				decipher[index] = ch;
				++pos;
				if (index > max_len)
					max_len = index;
				if (pos >= N)
					break;
			}
			++i;
			ch = cipher[i];
		}
		decipher[max_len + 1] = 0x00;
		puts(decipher);
	}

	return 0;
}
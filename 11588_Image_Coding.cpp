#include <stdio.h>

int X, R, C, M, N;

int arr[26];

void init()
{
	int i;
	for (i = 0; i < 26; ++i)
		arr[i] = 0;
}

int main()
{
	/*freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/

	char inp[100];
	int cn, i, k, max, val;
	int res;

	scanf("%d", &X);
	for (cn = 1; cn <= X; ++cn)
	{
		scanf("%d %d %d %d", &R, &C, &M, &N);
		init();
		max = 0;
		gets(inp);
		for (i = 0; i < R; ++i)
		{
			gets(inp);
			k = 0;
			while (inp[k])
			{
				val = inp[k] - 'A';
				++arr[val];
				if (arr[val] > max)
					max = arr[val];
				++k;
			}
		}

		res = 0;
		for (i = 0; i < 26; ++i)
		{
			if (arr[i] == max)
				res = res + (arr[i] * M);
			else
				res = res + (arr[i] * N);
		}

		printf("Case %d: %d\n", cn, res);
	}

	return 0;
}
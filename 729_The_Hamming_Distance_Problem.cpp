#include <stdio.h>

int N, H;

void back(int pos, int count, int ones, char arr[])
{
	int i;
	if (pos == N)
	{
		if (ones == H)
			puts(arr);
		return;
	}
	for (i = pos; i < N; ++i)
	{
		if (i > count)
			break;
		arr[i] = '0';
		back(i + 1, count + 1, ones, arr);
		if (ones < H)
		{
			arr[i] = '1';
			back(i + 1, count + 1, ones + 1, arr);
		}
	}
}

void loop()
{
	int i, a, count, k, l, limit;
	char arr[18] = { 0x00, };
	limit = 1 << N;
	arr[N] = 0x00;
	for (i = 1; i < limit; ++i)
	{
		count = 0;
		a = i;
		l = 1;
		while (a)
		{
			if (a & 1)
			{
				arr[N - l] = '1';
				++count;
			}
			else
				arr[N - l] = '0';
			a = a >> 1;
			++l;
		}
		if (a == 0 && count == H)
		{
			for (; l <= N; ++l)
				arr[N - l] = '0';
			puts(arr);
		}
	}
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T, i;
	char arr[18] = { 0x00, };
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &N, &H);
		arr[N] = 0x00;
		back(0, 0, 0, arr);

		//loop();

		if (T)
			printf("\n");
	}
	return 0;
}
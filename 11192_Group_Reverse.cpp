#include <stdio.h>

#define MAXN 101

char arr[MAXN];
int N;

void reverse()
{
	char tmp[MAXN];
	int i=0, j, len = 0;
	while (arr[++len]);
	N = len / N;
	while (arr[i])
	{
		j = i + (N - 2 * (i%N)) - 1;
		tmp[j] = arr[i];
		++i;
	}
	tmp[i] = arr[i];
	puts(tmp);
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	while (scanf("%d", &N) == 1 && N)
	{
		getchar();
		gets(arr);
		reverse();
	}
}
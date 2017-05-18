#include <stdio.h>
long long int arr[51];

void init()
{
	int i;
	arr[0] = 1;
	arr[1] = 1;
	for (i = 2; i < 51; ++i)
		arr[i] = arr[i - 1] + arr[i - 2];
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n;
	init();
	while (scanf("%d", &n) == 1 && n)
	{
		printf("%lld\n", arr[n]);
	}

	return 0;
}
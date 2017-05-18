#include <stdio.h>

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int v, t;
	while (scanf("%d %d", &v, &t) == 2)
	{
		printf("%d\n", (v * (t << 1)));
	}
	return 0;
}
#include <stdio.h>

int main()
{
	int T, a, b, n, s, cn;
	scanf("%d", &T);
	for (cn = 1; cn <= T; ++cn)
	{
		scanf("%d %d", &a, &b);
		if (!(a & 1))
			a += 1;
		if (!(b & 1))
			b -= 1;
		n = ((b - a) >> 1) + 1;
		s = ((n * (a + b)) >> 1);
		printf("Case %d: %d\n", cn, s);
	}
}